#include "header.h"
ready *head_ptr = NULL;

int count = 1;
int delete_flag = 0;
int save_flag = 1;
int display_file_flag = 1;

int main()
{
	load_from_file();  
	
	while(1)
	{
		printf("________________________________________________________________\n");
		printf("|**************************STUDENT RECORD**********************|\n");
		printf("|______________________________________________________________|\n");
		printf("|                      A/a :      Add a new record             |\n");
		printf("|                      D/d :      Delete a record              |\n");
		printf("|                      S/s :      Show the list                |\n");
		printf("|	               M/m :      Modify the record            |\n");
		printf("|                      V/v :      Save                         |\n");
		printf("|                      E/e :      Exit                         |\n");
		printf("|                      T/t :      Sort the list                |\n");
		printf("|                      R/r :      Reverse the list             |\n");
		printf("|______________________________________________________________|\n");

		printf("Enter the choice: ");	
		char options;
		scanf(" %c", &options);
				
		if(options == 'A' || options == 'a')
		{
			insert(&head_ptr);
		}
		else if(options == 'S' || options == 's')
		{
			display(head_ptr);
		}
		else if(options == 'D' || options == 'd')
		{
			delete_record(head_ptr);		
		}
		else if(options == 'M' || options == 'm')
		{
			mod(head_ptr);
		}
		else if(options == 'V' || options == 'v')
		{
			save(head_ptr);
		}
		else if(options == 'T' || options == 't')
		{
			sort(head_ptr);
		}
		else if(options == 'R' || options == 'r')
		{
			reverse_print(head_ptr);
		}
		else if(options == 'E' || options == 'e')  
		{
			int op = fun_exit();
			if(op == 1 || op == 0)
				return 0;
		}
	}
}
















