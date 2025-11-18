#include"header.h"
void load_from_file(void)
{
	FILE *fp = fopen("data_base.txt", "r");
	if(fp == NULL)
		return;
	
	int roll;
	char name[20];
	float marks;
	
	while(fscanf(fp, "%d %s %f", &roll, name, &marks) == 3)
	{
		ready *temp = (ready *)malloc(sizeof(ready));
		temp->roll = roll;
		strcpy(temp->name, name);
		temp->marks = marks;
		temp->next = NULL;
		
		if(head_ptr == NULL)
		{
			head_ptr = temp;
		}
		else
		{
			ready *ptr = head_ptr;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = temp;
		}
		
		if(roll >= count)
			count = roll + 1;
	}
	
	fclose(fp);
	display_file_flag = 0;
}
