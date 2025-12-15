#include"class.h"
#include<fstream>

int deletes_node = 0;
ui interface;

void node_act::add(const string& pre)
{
    if(pre == "Add New Book")
    {
        int buf;
        cout << "\nEnter the No of books: ";
        cin >> buf;
        
        for(int i = 0; i < buf; i++)
        {
            st *temp = new st();
            cout << "\n  Book " << (i+1) << ":" << endl;
            cout << "  Enter the book id: ";
            cin >> temp->book_id;
            cin.ignore();
            cout << "  Enter the book name: ";
            getline(cin, temp->book_name);
            cout << "  Enter the book count: ";
            cin >> temp->book_count;
            
            temp->left = NULL;
            temp->right = NULL;
            add_books(&head_ptr, temp);
            cout << "  Book added successfully!\n" << endl;
        }
    }
    else if(pre == "Issue Book")
    {
        user *temp = new user();
        cout << "\n  Enter the book_id: ";
        cin >> temp->book_id;
        
        st *book = search_node(head_ptr, temp->book_id, "");
        if(book == NULL)
        {
            cout << "  Book not found!" << endl;
            delete temp;
            return;
        }
        
        if(book->book_count <= 0)
        {
            cout << "  Book not available (all copies issued)!" << endl;
            delete temp;
            return;
        }
        
        temp->book_name = book->book_name;
        
        cout << "  Enter the user_id: ";
        cin >> temp->user_id;
        cin.ignore();
        cout << "  Enter user name: ";
        getline(cin, temp->user_name);
        cout << "  Enter issue_date (YYYYMMDD format, e.g., 20241215): ";
        cin >> temp->issue_date;
        temp->due_date = temp->issue_date + 7;
        
        temp->left = NULL;
        temp->right = NULL;
        add_issue(&user_head_ptr, temp);
        
        book->book_count--;
        
        cout << "  Book issued successfully! Due date: " << temp->due_date << endl;
    }
    else if(pre == "Update Book Details")
    {
        int id;
        cout << "\nEnter book ID to update: ";
        cin >> id;
        
        st *book = search_node(head_ptr, id, "");
        if(book == NULL)
        {
            cout << "Book not found!" << endl;
            return;
        }
        
        cout << "Current details - ID: " << book->book_id 
             << ", Name: " << book->book_name 
             << ", Count: " << book->book_count << endl;
        
        cin.ignore();
        cout << "Enter new book name (or press Enter to keep current): ";
        string new_name;
        getline(cin, new_name);
        if(!new_name.empty())
            book->book_name = new_name;
        
        cout << "Enter new book count: ";
        cin >> book->book_count;
        
        cout << "Book updated successfully!" << endl;
    }
}

void node_act::add_books(st **node, st *new_node)
{
    if(deletes_node != 0)
    {
        deleted_add(*node, new_node);
        deletes_node--;
        return;
    }
    
    if(*node == NULL)
    {
        *node = new_node;
        return;
    }
    else if((*node)->book_id > new_node->book_id)
    {
        add_books(&((*node)->right), new_node);
    }
    else
    {
        add_books(&((*node)->left), new_node);
    }
}

void node_act::add_issue(user **node, user *new_node)
{
    if(*node == NULL)
    {
        *node = new_node;
        return;
    }
    else if((*node)->book_id > new_node->book_id)
    {
        add_issue(&((*node)->right), new_node);
    }
    else
    {
        add_issue(&((*node)->left), new_node);
    }
}

void node_act::print_books(st *node)
{
    if(node != NULL)
    {
        print_books(node->left);
        
        if(node->book_id != 9999)
        {
            cout << "\n  Book ID: " << node->book_id 
                 << " | Name: " << node->book_name 
                 << " | Available: " << node->book_count << endl;
        }
        
        print_books(node->right);
    }
}

void node_act::print_issue(user *node)
{
    if(node != NULL)
    {
        print_issue(node->left);
        
        cout << "\n  Book ID: " << node->book_id 
             << " | Book: " << node->book_name 
             << " | User ID: " << node->user_id
             << " | User: " << node->user_name
             << " | Issue: " << node->issue_date 
             << " | Due: " << node->due_date << endl;
        
        print_issue(node->right);
    }
}

st* node_act::search_node(st *node, int id, string buffer)
{
    if(node == NULL)
        return NULL;
    
    if(node->book_id == id || (!buffer.empty() && node->book_name == buffer))
    {
        if(node->book_id != 9999)
            return node;
    }
    
    st *left_result = search_node(node->left, id, buffer);
    if(left_result != NULL)
        return left_result;
    
    return search_node(node->right, id, buffer);
}

user* node_act::user_search_node(user *node, int id, string buffer)
{
    if(node == NULL)
        return NULL;
    
    if(node->book_id == id || (!buffer.empty() && node->book_name == buffer))
        return node;
    
    user *left_result = user_search_node(node->left, id, buffer);
    if(left_result != NULL)
        return left_result;
    
    return user_search_node(node->right, id, buffer);
}

void node_act::update_node(st *node, int id, string book)
{
    if(node == NULL)
        return;
    
    if(node->book_id == id)
    {
        node->book_name = book;
        return;
    }
    
    update_node(node->left, id, book);
    update_node(node->right, id, book);
}

void node_act::deleted_add(st *node, st *new_node)
{
    if(node == NULL)
        return;
    
    if(node->book_id == 9999)
    {
        node->book_id = new_node->book_id;
        node->book_name = new_node->book_name;
        node->book_count = new_node->book_count;
        delete new_node;
        return;
    }
    
    deleted_add(node->left, new_node);
    deleted_add(node->right, new_node);
}

void node_act::delete_node(st *node, int id)
{
    if(node == NULL)
        return;
    
    if(node->book_id == id)
    {
        node->book_id = 9999;
        node->book_name = "";
        node->book_count = 0;
        deletes_node++;
        cout << "Book deleted successfully!" << endl;
        return;
    }
    
    delete_node(node->left, id);
    delete_node(node->right, id);
}

void node_act::_return(void)
{
    int book_id, today_date;
    cout << "\nEnter the book_id to return: ";
    cin >> book_id;
    
    user *issued = user_search_node(user_head_ptr, book_id, "");
    if(issued == NULL)
    {
        cout << "No issue record found for this book!" << endl;
        return;
    }
    
    st *book = search_node(head_ptr, book_id, "");
    if(book != NULL)
    {
        book->book_count++;
    }
    
    cout << "Enter today's date (YYYYMMDD format): ";
    cin >> today_date;
    
    if(today_date > issued->due_date)
    {
        int days_late = today_date - issued->due_date;
        int fine = days_late * 20;
        cout << "\nBook returned late!" << endl;
        cout << "Days late: " << days_late << endl;
        cout << "Fine amount: Rs." << fine << endl;
    }
    else
    {
        cout << "\nBook returned on time. Thank you!" << endl;
    }
    
    // In a full implementation, you'd remove the issue record here
}

void node_act::save_data(void)
{
    // Save books
    ofstream book_file("database_book.txt");
    if(!book_file.is_open())
    {
        cout << "Error saving book data!" << endl;
        return;
    }
    
    function<void(st*)> save_books = [&](st *node) {
        if(node != NULL)
        {
            save_books(node->left);
            if(node->book_id != 9999)
            {
                book_file << node->book_id << " " 
                         << node->book_name << " " 
                         << node->book_count << endl;
            }
            save_books(node->right);
        }
    };
    
    save_books(head_ptr);
    book_file.close();
    
    // Save issued books
    ofstream issue_file("database_issue.txt");
    if(!issue_file.is_open())
    {
        cout << "Error saving issue data!" << endl;
        return;
    }
    
    function<void(user*)> save_issues = [&](user *node) {
        if(node != NULL)
        {
            save_issues(node->left);
            issue_file << node->book_id << " " 
                      << node->user_id << " " 
                      << node->user_name << " " 
                      << node->book_name << " " 
                      << node->issue_date << " " 
                      << node->due_date << endl;
            save_issues(node->right);
        }
    };
    
    save_issues(user_head_ptr);
    issue_file.close();
    
    cout << "Data saved successfully!" << endl;
}