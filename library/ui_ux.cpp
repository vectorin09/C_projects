#include"class.h"
#include<iomanip>

node_act op;

void ui::main_ui(void)
{
    cout << "\n\n";
    cout << "-----------------------------------------------------" << endl;
    cout << "|              LIBRARY MANAGEMENT SYSTEM            |" << endl;
    cout << "-----------------------------------------------------" << endl;    
    cout << "| 1. Add New Book                                   |" << endl;
    cout << "| 2. Update Book Details                            |" << endl;
    cout << "| 3. Remove Book                                    |" << endl;
    cout << "| 4. Search Book                                    |" << endl;
    cout << "| 5. View All Books                                 |" << endl;
    cout << "| 6. Issue Book                                     |" << endl;
    cout << "| 7. Return Book                                    |" << endl;
    cout << "| 8. List Issued Books                              |" << endl;
    cout << "| 9. Save Data                                      |" << endl;
    cout << "| 10. Exit                                          |" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    string choice = preference();
    
    if(choice == "Add New Book" || choice == "Update Book Details" || choice == "Issue Book")
    {
        op.add(choice);
    }
    else if(choice == "View All Books")
    {
        cout << "\n========== ALL BOOKS ==========" << endl;
        op.print_books(head_ptr);
        cout << "===============================" << endl;
    }
    else if(choice == "Search Book")
    {
        int search_id;
        cout << "\nEnter Book ID to search: ";
        cin >> search_id;
        
        st *result = op.search_node(head_ptr, search_id, "");
        if(result != NULL)
        {
            cout << "\nBook Found!" << endl;
            cout << "  ID: " << result->book_id << endl;
            cout << "  Name: " << result->book_name << endl;
            cout << "  Available Count: " << result->book_count << endl;
        }
        else
        {
            cout << "\nBook not found!" << endl;
        }
    }
    else if(choice == "Remove Book")
    {
        int delete_id;
        cout << "\nEnter Book ID to remove: ";
        cin >> delete_id;
        op.delete_node(head_ptr, delete_id);
    }
    else if(choice == "Return Book")
    {
        op._return();
    }
    else if(choice == "List Issued Books")
    {
        cout << "\n========== ISSUED BOOKS ==========" << endl;
        op.print_issue(user_head_ptr);
        cout << "==================================" << endl;
    }
    else if(choice == "Save Data")
    {
        op.save_data();
    }
    else if(choice == "Exit")
    {
        cout << "\nSaving data before exit..." << endl;
        op.save_data();
        cout << "Thank you for using Library Management System!" << endl;
        exit(0);
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void ui::mem_ui(string menu)
{
    cout << " " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "  " << menu << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "| A. By Book ID                                     |" << endl;
    cout << "| B. By Book Name                                   |" << endl;
    cout << "| C. By Author Name                                 |" << endl;
    cout << "| D. Back to Main Menu                              |" << endl; 
    cout << "+---------------------------------------------------+" << endl;
}

void ui::show_ui(int book_id, string book_name)
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "| ID: " << setw(5) << book_id << " | Name: " << setw(40) << book_name << " |" << endl;
    cout << "-------------------------------------------------------------" << endl;
}
                         
string ui::preference()
{
    int buffer;
    cout << "\n  Enter your choice (1-10): ";
    cin >> buffer;
    
    string options[] = {
        "Add New Book", 
        "Update Book Details", 
        "Remove Book", 
        "Search Book", 
        "View All Books", 
        "Issue Book", 
        "Return Book", 
        "List Issued Books", 
        "Save Data", 
        "Exit"
    };
    
    if(buffer < 1 || buffer > 10)
    {
        cout << "Invalid choice! Please try again." << endl;
        return "Invalid";
    }
    
    return options[buffer - 1];
}