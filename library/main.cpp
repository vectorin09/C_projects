#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
class st
{
        public:
		int value;
                int book_id;
                st*prev;
                st*next;
        void stt(int value)
        {
                book_id=value;
                st*prev=NULL;
                st*next=NULL;
        }


};
class ui
{
	int buffer=0;
	const char* enter="  Enter the choices : ";

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
			mem_ui(preference());
			
				
			
								


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
			if(menu == "Add New Book")
			{
				add();
			}


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
		void add(void)
		{
			st node;
			cout<<enter;
			cin>>buffer;
			st*temp;
			temp=new st ;
			if(buffer == 1) 
			{
				node.stt(10);
				cout<<node.book_id<<endl;	

			}
			while(1);

		}

};
int main()
{
	ui a;
	while(1)
	{
		if(a.exit == 1)
			return 0;
		a.main_ui();
	}
		
}
			
