#include"header.h"
void display(ready *temp)
{
	if(temp == NULL)
	{
		printf("\nNo records to display!\n");
		char options;
		printf("Enter any key to exit: ");
		scanf(" %c", &options);
		return;
	}
	printf("\n");
	
	printf("************************Student Details*****************************\n");
	printf("| Roll |        NAME        |       Marks        %20c\n",'|');
	printf("---------------------------------------------------------------------\n");
	
	int has_records = 0;
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)  
		{
			printf("|%-8d %-20s %.2f %32c\n", temp->roll, temp->name, temp->marks,'|');
			printf("---------------------------------------------------------------------\n");
			has_records = 1;
		}
		temp = temp->next;
	}
	
	if(!has_records)
		printf("No active records!\n");
	
	char options;
	printf("\nEnter any key to exit: ");
	scanf(" %c", &options);
}
