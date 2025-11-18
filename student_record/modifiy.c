#include"header.h"
void mod(ready *head_ptr)
{
	if(head_ptr == NULL)
	{
		printf("No records to modify!\n");
		return;
	}
	printf("\n");
	printf("_______________________________________________________\n");
	printf("|******************Requirements***********************|\n");
	printf("|            N/n : search by name                     |\n");
	printf("|            R/r : search by roll                     |\n");
	printf("|_____________________________________________________|\n");
	printf("Enter the choice: ");
	char op;
	scanf(" %c", &op);
	ready *temp = head_ptr;
	
	if(op == 'N' || op == 'n')
	{
		char name[20];
		printf("Enter the name to find: ");
		scanf("%s", name);
		
		int found = 0;
		while(temp != NULL)
		{
			if(strcmp(name, temp->name) == 0)
			{
				printf("\n************************Student Details*****************************\n");
				printf("| Roll |        NAME        |       Marks        |\n");
				printf("---------------------------------------------------------------------\n");
				char checking;
				printf("|%-8d %-20s %.2f %32c\n", temp->roll, temp->name, temp->marks,'|');
				printf("---------------------------------------------------------------------\n");
				printf("PRESS Y TO CONFIRM:");
				scanf(" %c",&checking);
				found = 1;
				if(checking == 'Y'||'y')
				{
					char mod_op;
					printf("\n|*************************Requirements*****************|\n");
					printf("|            N/n : change the name                    |\n");
					printf("|            P/p : change the marks                   |\n");
					printf("******************************************************|\n");
					printf("Enter the choice:");
					scanf(" %c", &mod_op);
				
					if(mod_op == 'N' || mod_op == 'n')
					{
						char new_name[20];
						printf("Enter the new name: ");
						scanf("%s", new_name);
						strcpy(temp->name, new_name);
						printf("Name updated successfully!\n");
					}
					else if(mod_op == 'P' || mod_op == 'p')
					{
						float mark;
						printf("Enter the new marks: ");
						scanf("%f", &mark);
						temp->marks = mark;
						printf("Marks updated successfully!\n");
					}
					save_flag = 1; 
					break;
				}	
			}
			temp = temp->next;
		}
		if(!found)
			printf("Name not found!\n");
	}
	else if(op == 'R' || op == 'r')
	{
		int mod_roll;
		printf("Enter the roll no to find: ");
		scanf("%d", &mod_roll);
		
		int found = 0;
		while(temp != NULL)
		{

			if(temp->roll == mod_roll)
			{
				printf("\n************************Student Details*****************************\n");
				printf("| Roll |        NAME        |       Marks        |\n");
				printf("---------------------------------------------------------------------\n");
				char checking;
				printf("|%-8d %-20s %.2f %32c\n", temp->roll, temp->name, temp->marks,'|');
				printf("---------------------------------------------------------------------\n");
				printf("PRESS Y TO CONFIRM");
				scanf(" %c",&checking);
				if(checking == 'Y'||checking =='y')
				{
					found = 1;
					char mod_op;
					printf("\n|*************************Requirements*****************|\n");
					printf("|            N/n : change the name                    |\n");
					printf("|            P/p : change the marks                   |\n");
					printf("******************************************************|\n");
					printf("             Enter the choice: ");
					scanf(" %c", &mod_op);
					
					if(mod_op == 'N' || mod_op == 'n')
					{
						char new_name[20];
						printf("Enter the new name: ");
						scanf("%s", new_name);
						strcpy(temp->name, new_name);
						printf("Name updated successfully!\n");
					}	
					else if(mod_op == 'P' || mod_op == 'p')
					{
						float mark;
						printf("Enter the new marks: ");
						scanf("%f", &mark);
						temp->marks = mark;
						printf("Marks updated successfully!\n");
					}	
					save_flag = 1; 
					break;
				}
			}
			temp = temp->next;
		}
		if(!found)
			printf("Roll number not found!\n");
	}
}
