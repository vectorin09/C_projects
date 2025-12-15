#include<iostream>
#include<fstream>
#include<sstream>
#include"class.h"

using namespace std;

node_act cl;
st *head_ptr = NULL;
user *user_head_ptr = NULL;

void load_books()
{
    ifstream fp("database_book.txt");
    if(!fp.is_open())
    {
        cout << "Book database file not found. Starting with empty library." << endl;
        return;
    }
    
    int book_id, book_count;
    string book_name;
    
    while(fp >> book_id >> book_name >> book_count)
    {
        st *temp = new st();
        temp->book_id = book_id;
        temp->book_name = book_name;
        temp->book_count = book_count;
        temp->left = NULL;
        temp->right = NULL;
        cl.add_books(&head_ptr, temp);
    }
    
    fp.close();
    cout << "Books loaded successfully!" << endl;
}

void load_issued_books()
{
    ifstream fp("database_issue.txt");
    if(!fp.is_open())
    {
        cout << "Issue database file not found. Starting with no issued books." << endl;
        return;
    }
    
    int book_id, user_id, issue_date, due_date;
    string user_name, book_name;
    
    while(fp >> book_id >> user_id >> user_name >> book_name >> issue_date >> due_date)
    {
        user *temp = new user();
        temp->book_id = book_id;
        temp->user_id = user_id;
        temp->user_name = user_name;
        temp->book_name = book_name;
        temp->issue_date = issue_date;
        temp->due_date = due_date;
        temp->left = NULL;
        temp->right = NULL;
        cl.add_issue(&user_head_ptr, temp);
    }
    
    fp.close();
    cout << "Issued books loaded successfully!" << endl;
}

int main()
{
    cout << "Loading library data..." << endl;
    load_books();
    load_issued_books();
    cout << "\nLibrary Management System Ready!\n" << endl;
    
    while(true)
    {
        interface.main_ui();
    }
    
    return 0;
}