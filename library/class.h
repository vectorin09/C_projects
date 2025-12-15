#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<string>
using namespace std;

class st
{
    public:
        int book_id;
        string book_name;
        st *left;
        st *right;
        int book_count;
        
        st() : book_id(0), book_name(""), left(NULL), right(NULL), book_count(0) {}
};

typedef struct user
{
    int book_id;
    int user_id;
    string user_name;
    string book_name;
    int issue_date;
    int due_date;
    user *left;
    user *right;
    
    user() : book_id(0), user_id(0), user_name(""), book_name(""), 
             issue_date(0), due_date(0), left(NULL), right(NULL) {}
}user;

extern st *head_ptr;
extern user *user_head_ptr;

class node_act
{
    public:
        void add(const string& pre);
        void add_books(st** node, st *new_node);
        void add_issue(user **node, user *new_node);
        void print_books(st *head_ptr);
        void print_issue(user *user_head_ptr);
        st* search_node(st *head, int id, string buffer);
        user* user_search_node(user *head_ptr, int id, string buffer);
        void update_node(st *head_ptr, int id, string book);
        void deleted_add(st *node, st *new_node);
        void delete_node(st *node, int id);
        void _return(void);
        void save_data(void);
};

class ui
{
    public:
        void main_ui(void);
        void mem_ui(string menu);
        void show_ui(int book_id, string book_name);
        string preference();
}; 

extern node_act cl;
extern ui interface;

#endif