#include"header.h"
void insert(ready **head_ptr)
{
	display_file_flag = 0;
	save_flag = 1;  
	
	ready *temp = (ready *)malloc(sizeof(ready));
	
	printf("----------------------------------------------\n");
	printf("        Enter The Student Name: ");
	scanf("%s", temp->name);
	printf("----------------------------------------------\n");
	printf("        Enter The Marks: ");
	scanf("%f", &temp->marks);
	
	temp->roll = count;
	temp->next = NULL;
	count++;
	
	
	if(delete_flag > 0)
	{
		ready *ptr = *head_ptr;
		while(ptr != NULL)
		{
			if(strcmp(ptr->name, "") == 0)
			{
				strcpy(ptr->name, temp->name);
				ptr->marks = temp->marks;
				free(temp);
				delete_flag--;
				printf("Record added successfully!\n");
				return;
			}
			ptr = ptr->next;
		}
	}

	if(*head_ptr == NULL)
	{
		*head_ptr = temp;
	}
	else
	{
		ready *temper = *head_ptr;
		while(temper->next != NULL)
		{
			temper = temper->next;
		}
		temper->next = temp;
	}
	
	printf("Record added successfully!\n");
}
