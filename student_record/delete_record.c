
#include"header.h"
void delete_record(ready *temp)
{
	if(temp == NULL)
	{
		printf("No records to delete!\n");
		return;
	}
	
	char dele_op;
	printf("\n|*************************Enter***********************|\n");
	printf("|            R/r : Enter Roll no to delete            |\n");
	printf("|            N/n : Enter the name to delete           |\n");
	printf("******************************************************|\n");
	printf("Enter the choice: ");
	scanf(" %c", &dele_op);

	if(dele_op == 'R' || dele_op == 'r')
	{
		int roll;
		printf("Enter the roll no: ");
		scanf("%d", &roll);
		
		ready *temper = temp;
		int found = 0;
		while(temper != NULL)
		{
			if(temper->roll == roll)
			{
				printf("\n************************Student Details*****************************\n");
				printf("| Roll |        NAME        |       Marks        |\n");
				printf("---------------------------------------------------------------------\n");
				char checking;
				printf("|%-8d %-20s %.2f %32c\n", temper->roll, temper->name, temper->marks,'|');
				printf("---------------------------------------------------------------------\n");
				printf("PRESS Y TO CONFIRM: ");
				scanf(" %c",&checking);
				found=1;
				if(checking == 'y'||checking =='Y')
				{
					delete_flag++;
					found = 1;
					strcpy(temper->name, "");
					temper->marks = 0;
					printf("Record deleted successfully!\n");
					break;
				}
				else
					
					break;
			}
			temper = temper->next;
		}
		if(!found)
			printf("Roll number not found!\n");
	}
	else if(dele_op == 'N' || dele_op == 'n')
	{
		char check_str[20];
		printf("Enter the name: ");
		scanf("%s", check_str);
		
		ready *temper = temp;
		int found = 0;
		while(temper != NULL)
		{
			if(strcmp(temper->name, check_str) == 0)
			{
				printf("\n************************Student Details*****************************\n");
				printf("| Roll |        NAME        |       Marks        |\n");
				printf("---------------------------------------------------------------------\n");
				char checking;
				printf("|%-8d %-20s %.2f %32c\n", temper->roll, temper->name, temper->marks,'|');
				printf("---------------------------------------------------------------------\n");
				printf("PRESS Y TO CONFIRM");
				scanf(" %c",&checking);
				found=1;
				if(checking == 'Y'||checking =='y')
				{
					delete_flag++;
					found = 1;
					strcpy(temper->name, "");
					temper->marks = 0;
					printf("Record deleted successfully!\n");
					break;
				}
			}
			temper = temper->next;
		}
		if(!found)
			printf("Name not found!\n");
	}
}
