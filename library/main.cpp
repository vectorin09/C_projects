#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<iomanip>

int buffer=0;
int deletes=0;
const char* enter="  Enter the choices : ";
using namespace std;
class st
{
        public:
		
	        int book_id;
		std::	string  book_name;
                st*left;
                st*right;
       		
	


};
st *head_ptr=NULL;
class node_act
{
	public:
        	void add()
        	{
			
			
			st*temp;
			temp =new st;
        	        cout<<"Enter the book id:";
			cin>>temp->book_id;
			cout<<"Enter the book name:";
			cin>>temp->book_name;
			temp->left=NULL;
			temp->right=NULL;
        	        add_tree(&head_ptr,temp);
			//system("clear");
			//print_tree(head_ptr);
		

        	}
		void add_tree(st**node,st*new_node)
		{
			if(deletes !=0)
			{
				deleted_add(*node,new_node);
				deletes--;
				return;
			}
			if(*node==NULL)
			{
				*node=new_node;
				return;
			}
			else if(((*node)->book_id ) > (new_node->book_id))
			{
			
				add_tree((&(*node)->right),new_node);

			}
		       	else
			{
				add_tree((&(*node)->left),new_node);	
			}
		}
		void print_tree(st*head_node)
		{
			
			if(head_node!=NULL)
			{

	    			//cout<<head_node->book_name<<"->";
	    			cout<<head_node->book_id<<"->";
				print_tree(head_node->left);
				print_tree(head_node->right);
			

			}
			else
			{
				
				return;
			}
		}
		
	  	st *search_node(st*head_ptr,int id,string buffer)
		{
			if(head_ptr == NULL)
				return NULL;
			if(head_ptr ->book_id == id||head_ptr->book_name == buffer )
			{
				return head_ptr;
			}
		       	search_node(head_ptr->left,id,buffer);
			search_node(head_ptr->right,id,buffer);
		}
		void update_node(st*head_ptr,int id,char* book)
		{
			 if(head_ptr == NULL)
                                return ;
                        if(head_ptr ->book_id == id )
                        {
                                 head_ptr->book_id=999;
				 cout<<head_ptr->book_id<<endl;
				 return;
                        }
                        update_node(head_ptr->left,id,book);
                        update_node(head_ptr->right,id,book);
		}
		void deleted_add(st*node,st*new_node)
		{
			if(node==NULL)
			{
				return;

			}
			if(node->book_id == 9999)
			{
				node->book_id =new_node->book_id;
				node->book_name=new_node->book_name;
				return;
			}
			deleted_add(node->left,new_node);
			deleted_add(node->right,new_node);
		}
		void delete_node(st*node,int id)
		{
			if(node == NULL)
                                return ;
                        if(node->book_id == id )
                        {
				node->book_id =9999;
				node->book_name=" ";
				deletes++;
                                return ;
                        }
                        delete_node(node->left,id);
                        delete_node(node->right,id);

		}

		
};

class ui
{
	public:	
		int exit=0;
	public:
		void main_ui(void)
		{
			
			cout<<"-----------------------------------------------------"<<endl;
			cout<<"|                   LIBRARY HOME PAGE               |"<<endl;
			cout<<"-----------------------------------------------------"<<endl;	
			cout<<"|1.Add New Book                                     |"<<endl;
			cout<<"|2.update Book Details                              |"<<endl;
			cout<<"|3.Remove Book                                      |"<<endl;
			cout<<"|4.Search Book                                      |"<<endl;
			cout<<"|5.View All Books                                   |"<<endl;
			cout<<"|6.Issuse Book                                      |"<<endl;
			cout<<"|7.Return Book                                      |"<<endl;
			cout<<"|8.List Issued Books                                |"<<endl;
			cout<<"|9.Save                                             |"<<endl;
			cout<<"|10.Exit                                            |"<<endl;
			cout<<"-----------------------------------------------------"<<endl;
						
	
	
			
								


		}
		void  mem_ui(string menu)
		{
			cout<<" "<<endl;
			cout<<"----------------------------------------------------"<<endl;
			cout<<menu<<endl;
			cout<<"----------------------------------------------------"<<endl;
			cout<<"|A. By Book ID                                      |"<<endl;
			cout<<"|B. By Book Name                                    |"<<endl;
			cout<<"|C. By Author Name                                  |"<<endl;
			cout<<"|D. Back to Main Menu                               |"<<endl; 
			cout<<"+---------------------------------------------------+"<<endl;
			


		}
		void show_ui(string book_id,string book_name)
		{
			cout<<"-------------------------------------------------------------"<<endl;
			int width=60;
			string content=book_id+"  |  "+book_name;
			int padding=width-2-content.size();
			if(padding <0) padding=0;
			cout<<"|"<<content<<string(padding,' ')<<"|"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
		}
	                             
		string preference()
		{

			cout<<"  Enter the choices : ";
			cin>>buffer;

			char array[][20]={"Add New Book","update Book Details","Remove Book","Search Book","View All Books","Issuse Book","Return Book","List Issued Books","Save","Exit"};
			if(buffer >= 10) _Exit(0);
			
			else
				return array[buffer-1];
		
			
			
		}

		

};
int main()
{
	
	int buf=0;
	node_act details;
	cout<<"Enter the inputs:";
	cin>>buf;
	for(int i=0;i<buf;i++)
	{
		details.add();
	}
	details.update_node(head_ptr,43,"dfd");
	details.print_tree(head_ptr);


}
			
