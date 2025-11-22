#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<iomanip>

int buffer=0;
const char* enter="  Enter the choices : ";
using namespace std;
class st
{
        public:
		
	        int book_id;
		string book_name;
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
			print_tree(head_ptr);
		

        	}
		void add_tree(st**node,st*new_node)
		{
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

				cout<<head_node->book_name<<"->";
				print_tree(head_node->left);
				print_tree(head_node->right);
			

			}
			else
			{
				
				return;
			}
		}
		
	  	int search_node(st*head_ptr,string node=" ",int id=1111)
		{
			if((head_ptr ->book_id == id )|| (strcpy(head_ptr->book_name,node)==1))
				return 1;
			else if(head_ptr != NULL)
			{
		       	
				search_node(head_ptr->left,node,id);
		       	
				search_node(head_ptr->right,node,id);
				

			}	
			else
		       	{
				return -1;
			}
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
		int  mem_ui(string menu)
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
		string preference()
		{

			cout<<"  Enter the choices : ";
			cin>>buffer;

			char array[][20]={"Add New Book","update Book Details","Remove Book","Search Book","View All Books","Issuse Book","Return Book","List Issued Books","Save","Exit"};
			if(buffer == 10) exit=1;
			
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
	buf=0;
	buf=details.search_node(head_ptr,"kuthu");
	if(buf == 1)
		cout<<"yeah we have those details";
	else
		cout<<"naah we don't have those details";
	
		
}
			
