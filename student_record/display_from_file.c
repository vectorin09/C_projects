#include"header.h"
void display_from_file(void)
{
	FILE *file_open = fopen("data_base.txt", "r");
	if(file_open == NULL)
	{
		printf("No saved records found!\n");
		return;
	}
	
	printf("\n************************Student Details*****************************\n");
	printf("| Roll |        NAME        |       Marks        |\n");
	printf("---------------------------------------------------------------------\n");
	
	int roll;
	char name[20];
	float marks;
	
	while(fscanf(file_open, "%d %s %f", &roll, name, &marks) == 3)
	{
		printf("  %-6d %-20s %.2f\n", roll, name, marks);
		printf("---------------------------------------------------------------------\n");
	}
	
	fclose(file_open);
}

