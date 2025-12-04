#include<iostream>
#include<string.h>
using namespace std;
class st
{
        public:
		
	        int book_id;
		std::string  book_name;
                st*left;
                st*right;
		int book_count;
       		
	


};
typedef struct user
{
	int book_id;
	int user_id;
	char*user_name=NULL;
	char*book_name=NULL;
	int issue_date;
	int due_date;
	user *left=NULL;
	user *right=NULL;
}user;
extern st *head_ptr;
extern user*user_head_ptr;


class node_act
{
	public:
	
		void add(const char* pre);
		void add_books(st** node,st*new_node);
		void add_issue(user**node,user*new_node);
		void print_books(st*head_ptr);
		void print_issue(user*user_head_ptr);
		st*search_node(st*head,int id,string buffer);
		user*user_search_node(user*head_ptr,int id,string buffer);
		void update_node(st*head_ptr,int id,char*book);
		void deleted_add(st*node,st*new_node);
		void delete_node(st*node,int id);
		void _return(void);

};
class ui
{
	public:
		
		void main_ui(void);
		void mem_ui(string menu);
		void show_ui(int  book_id,string book_name);
		string preference();

}; 
extern node_act  cl;

extern ui interface;

