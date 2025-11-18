#include"header.h"
void save(ready *head_ptr)
{
	FILE *file = fopen("data_base.txt", "w");  
	if(file == NULL)
	{
		printf("Error opening file!\n");
		return;
	}
	
	ready *temp = head_ptr;
	int saved_count = 0;
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)  
		{
			fprintf(file, "%d %s %.2f\n", temp->roll, temp->name, temp->marks);
			saved_count++;
		}
		temp = temp->next;
	}
	
	fclose(file);  
	save_flag = 0;
	printf("\n%d records saved successfully!\n", saved_count);
}

