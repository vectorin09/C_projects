#include"header.h"
int fun_exit()
{
	if(save_flag)
	{
		char op;
		printf("**************************************************\n");
		printf("You have unsaved changes!\n");
		printf("V/v: Save and exit\n");
		printf("E/e: Exit without saving\n");
		printf("**************************************************\n");
		printf("Enter your choice: ");
		scanf(" %c", &op);
		
		if(op == 'V' || op == 'v')
		{
			save(head_ptr);
			printf("\nExiting...\n");
			return 0;
		}
		else
		{
			printf("\nExiting without saving...\n");
			return 0;
		}
	}
	else
	{
		printf("\nExiting...\n");
		return 1;
	}
}
