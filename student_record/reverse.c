#include"header.h"
void reverse_print(ready *head_ptr)
{
	if(head_ptr == NULL)
	{
		printf("No records to display!\n");
		return;
	}
	
	
	int count = 0;
	ready *temp = head_ptr;
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)
			count++;
		temp = temp->next;
	}
	
	if(count == 0)
	{
		printf("No active records to display!\n");
		return;
	}
	
	
	ready **arr = (ready **)malloc(count * sizeof(ready *));
	int idx = 0;
	temp = head_ptr;
	
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)
		{
			arr[idx++] = temp;
		}
		temp = temp->next;
	}
	
	
	printf("\n******************Reversed View (Not Saved)******************\n");
	printf("| Roll |        NAME        |    Department    |       Marks        |\n");
	printf("---------------------------------------------------------------------\n");
	
	for(int i = count - 1; i >= 0; i--)
	{
		printf("  %-6d %-20s %.2f\n", arr[i]->roll, arr[i]->name, 
		       arr[i]->marks);
		printf("---------------------------------------------------------------------\n");
	}
	
	free(arr);
	
	char options;
	printf("\nEnter any key to return to menu: ");
	scanf(" %c", &options);
}
