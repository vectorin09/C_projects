#include"class.h"

int buffer=0;
int deletes=0;
node_act op;
		void ui::main_ui(void)
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
			string _65=preference();
			if((_65!="Add New Book")&&(_65!="update Book Details")&&(_65!="Issuse Book")&&(_65!="View All Books"))
				mem_ui(_65);
			else if(_65 == "View All Books")
			{
				
				op.print_books(head_ptr);
			}	
			else 
			{
			
				op.add(_65.c_str());
			}
						
	
	
			
								


		}
		void ui::mem_ui(string menu)
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
		void ui::show_ui(int book_id,string book_name)
		{
			cout<<"-------------------------------------------------------------"<<endl;
			int width=60;
			string content=book_id+"|"+book_name;
			int padding=width-2-content.size();
			if(padding <0) padding=0;
			cout<<"|"<<content<<string(padding,' ')<<"|"<<endl;
			cout<<"-------------------------------------------------------------"<<endl;
		}
	                             
		string ui::preference()
		{

			cout<<"  Enter the choices : ";
			cin>>buffer;

			char array[][20]={"Add New Book","update Book Details","Remove Book","Search Book","View All Books","Issuse Book","Return Book","List Issued Books","Save","Exit"};
			if(buffer >= 10) _Exit(0);
			
			else
				return array[buffer-1];
		
			
			
		}

		
