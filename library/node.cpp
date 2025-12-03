#include"class.h"
#include<sys/wait.h>
int buffer=0;
int deletes=0;
	 	void node_act::add(const char*pre)
        	{
			
			if(strcmp(pre,"Add New Book\0")==0)
			{
				int buf;
				cout<<"Enter the No of books:";
        			cin>>buf;
        			for(int i=0;i<buf;i++)
				{
					st*temp;
					temp =new st;
        	       			cout<<"Enter the book id:";
					cin>>temp->book_id;
					cout<<"Enter the book name:";
					cin>>temp->book_name;
					temp->left=NULL;
					temp->right=NULL;
					temp->book_count=temp->book_count+1;
        	       			add_books(&head_ptr,temp);
					cout<<temp->book_count<<endl;
					//system("clear");
					//print_tree(head_ptr);
				}
			}
			else if(strcmp(pre,"Issuse Book\0")==0)
			{
				user*temp;
				temp=(user*)malloc(sizeof(user));
				cout<<"Enter the book_id :";
				cin>>temp->book_id;
				cout<<"Enter the user_id :";
				cin>>temp->user_id;
				cout<<"Enter issue_date :";
				cin>>temp->issue_date;
				temp->due_date=temp->issue_date+7;
				add_issue(&user_head_ptr,temp);
				print_issue(user_head_ptr);

			}

        	}

		void node_act::add_books(st**node,st*new_node)
		{
			int status;
			wait(&status);


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
			
				add_books((&(*node)->right),new_node);
				

			}
		       	else
			{
				add_books((&(*node)->left),new_node);	
				
			}
		}
		void node_act::add_issue(user**node,user*new_node)
                {
                        
                        if(*node==NULL)
                        {
                                *node=new_node;
                                return;
                        }
                        else if(((*node)->book_id ) > (new_node->book_id))
                        {

                                add_issue((&(*node)->right),new_node);

                        }
                        else
                        {
                                add_issue((&(*node)->left),new_node);
                        }
                }
		void node_act::print_books(st*head_node)
		{
			
			if(head_node!=NULL)
			{

	    			//cout<<head_node->book_name<<"->";
	    			//cout<<head_node->book_id<<"->";
				interface.show_ui(head_node->book_id,head_node->book_name);
				print_books(head_node->left);
				print_books(head_node->right);
			

			}
			else
			{
				
				return;
			}
		}
		void node_act::print_issue(user*head_node)
                {

                        if(head_node!=NULL)
                        {

                                //cout<<head_node->book_id<<"->";
				interface.show_ui(head_node->book_id,head_node->book_name);
                                print_issue(head_node->left);
                                print_issue(head_node->right);


                        }
                        else
                        {

                                return;
                        }
                }

		st* node_act::search_node(st*head_ptr,int id,string buffer)
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
		user* node_act::user_search_node(user*head_ptr,int id,string buffer)
                {
                        if(head_ptr == NULL)
                                return NULL;
                        if(head_ptr ->book_id == id||head_ptr->book_name == buffer )
                        {
                                return head_ptr;
                        }
                        user_search_node(head_ptr->left,id,buffer);
                        user_search_node(head_ptr->right,id,buffer);
                }

		void node_act::update_node(st*head_ptr,int id,char* book)
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
		void node_act::deleted_add(st*node,st*new_node)
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
		void node_act::delete_node(st*node,int id)
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
		void node_act::_return (void)
		{
			int data,today_date;
			cout<<"Enter the book_id which you want to return :";
			cin>>data;
			st*temp=search_node(head_ptr,data," ");
			temp->book_count=temp->book_count++;
			user*temp1=user_search_node(user_head_ptr,data,"");
			if(temp1 == NULL)
			{
				
				cout<<"the details not found on issued list"<<endl;
				return;
			}
			cout<<"Enter the today date: ";
			cin>>today_date;
			if(today_date > (temp1->due_date))
			{
				cout<<"you have to pay an fine Rs."<<((today_date)-(temp1->due_date))*20<<endl;
			}
			else 
			{
				//setlocale(SET_ALL,"");
				//wchar_t=;
				//wchar_t(hex);

				cout<<"you free to leave"<<endl;
				
			}
		}

		
