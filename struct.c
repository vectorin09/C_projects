#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	char name[20];
	int roll;
	float marks;
	struct student *next;
}ready;

ready *head_ptr = NULL;

int count = 1;
int delete_flag = 0;
int save_flag = 1;
int display_file_flag = 1;

void display(ready*);
void delete(ready *);
void insert(ready **);  
void mod(ready *);
void save(ready*);
void sort(ready *);
int fun_exit();
void display_from_file(void);
void load_from_file(void);
void reverse_print(ready *head_ptr);

int main()
{
	load_from_file();  // Load existing data on startup
	
	while(1)
	{
		printf("\n******************************STUDENT RECORD*******************\n");
		printf("|                      A/a :      Add a new record             |\n");
		printf("|                      D/d :      Delete a record              |\n");
		printf("|                      S/s :      Show the list                |\n");
		printf("|                      M/m :      Modify the record            |\n");
		printf("|                      V/v :      Save                         |\n");
		printf("|                      E/e :      Exit                         |\n");
		printf("|                      T/t :      Sort the list                |\n");
		printf("|                      R/r :      Reverse the list             |\n");
		printf("****************************************************************\n");

		printf("                      Enter the choice: ");	
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
			delete(head_ptr);		
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
		else if(options == 'E' || options == 'e')  // FIXED: proper condition
		{
			int op = fun_exit();
			if(op == 1 || op == 0)
				return 0;
		}
	}
}

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

void delete(ready *temp)
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
				delete_flag++;
				found = 1;
				strcpy(temper->name, "");
				temper->marks = 0;
				printf("Record deleted successfully!\n");
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
				delete_flag++;
				found = 1;
				strcpy(temper->name, "");
				temper->marks = 0;
				printf("Record deleted successfully!\n");
				break;
			}
			temper = temper->next;
		}
		if(!found)
			printf("Name not found!\n");
	}
}

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
	
	printf("\n************************Student Details*****************************\n");
	printf("| Roll |        NAME        |       Marks        |\n");
	printf("---------------------------------------------------------------------\n");
	
	int has_records = 0;
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)  // Skip deleted records
		{
			printf("  %-6d %-20s %.2f\n", temp->roll, temp->name, temp->marks);
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

void insert(ready **head_ptr)
{
	display_file_flag = 0;
	save_flag = 1;  // Mark as unsaved
	
	ready *temp = (ready *)malloc(sizeof(ready));
	
	printf("----------------------------------------------\n");
	printf("        Enter The Student Name: ");
	scanf("%s", temp->name);
	printf("----------------------------------------------\n");
	printf("        Enter The Department: ");
	scanf("%s", temp->department);
	printf("----------------------------------------------\n");
	printf("        Enter The Marks: ");
	scanf("%f", &temp->marks);
	
	temp->roll = count;
	temp->next = NULL;
	count++;
	
	// Try to reuse deleted slot
	if(delete_flag > 0)
	{
		ready *ptr = *head_ptr;
		while(ptr != NULL)
		{
			if(strcmp(ptr->name, "") == 0)
			{
				strcpy(ptr->name, temp->name);
				strcpy(ptr->department, temp->department);
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

void mod(ready *head_ptr)
{
	if(head_ptr == NULL)
	{
		printf("No records to modify!\n");
		return;
	}
	
	printf("\n|*************************Requirements*****************|\n");
	printf("|            N/n : search by name                     |\n");
	printf("|            R/r : search by roll                     |\n");
	printf("******************************************************|\n");
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
				found = 1;
				char mod_op;
				printf("\n|*************************Requirements*****************|\n");
				printf("|            N/n : change the name                    |\n");
				printf("|            P/p : change the marks                   |\n");
				printf("|            D/d : change the department              |\n");
				printf("******************************************************|\n");
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
				else if(mod_op == 'D' || mod_op == 'd')
				{
					char dept[8];
					printf("Enter the new department: ");
					scanf("%s", dept);
					strcpy(temp->department, dept);
					printf("Department updated successfully!\n");
				}
				save_flag = 1;  // Mark as unsaved
				break;
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
				found = 1;
				char mod_op;
				printf("\n|*************************Requirements*****************|\n");
				printf("|            N/n : change the name                    |\n");
				printf("|            P/p : change the marks                   |\n");
				printf("|            D/d : change the department              |\n");
				printf("******************************************************|\n");
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
				else if(mod_op == 'D' || mod_op == 'd')
				{
					char dept[8];
					printf("Enter the new department: ");
					scanf("%s", dept);
					strcpy(temp->department, dept);
					printf("Department updated successfully!\n");
				}
				save_flag = 1;  // Mark as unsaved
				break;
			}
			temp = temp->next;
		}
		if(!found)
			printf("Roll number not found!\n");
	}
}

void save(ready *head_ptr)
{
	FILE *file = fopen("data_base.txt", "w");  // FIXED: use "w" not "a"
	if(file == NULL)
	{
		printf("Error opening file!\n");
		return;
	}
	
	ready *temp = head_ptr;
	int saved_count = 0;
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)  // Don't save deleted records
		{
			fprintf(file, "%d %s %.2f\n", temp->roll, temp->name, temp->marks);
			saved_count++;
		}
		temp = temp->next;
	}
	
	fclose(file);  // FIXED: moved outside loop
	save_flag = 0;
	printf("\n%d records saved successfully!\n", saved_count);
}

void sort(ready *head_ptr)
{
	if(head_ptr == NULL)
	{
		printf("No records to sort!\n");
		return;
	}
	
	ready *sort_head_ptr = NULL;	
	ready *temp = head_ptr;
	
	// Create a sorted copy (temporary)
	while(temp != NULL)
	{
		if(strcmp(temp->name, "") != 0)  // Skip deleted records
		{
			ready *sort_temp = (ready *)malloc(sizeof(ready));	
			strcpy(sort_temp->name, temp->name);
			strcpy(sort_temp->department, temp->department);
			sort_temp->marks = temp->marks;
			sort_temp->roll = temp->roll;
			sort_temp->next = NULL;
			
			if(sort_head_ptr == NULL)
			{
				sort_head_ptr = sort_temp;
			}
			else
			{
				ready *sort_iter = sort_head_ptr;
				ready *prev = NULL;
				
				// Find insertion point
				while(sort_iter != NULL && strcmp(sort_temp->name, sort_iter->name) > 0)
				{
					prev = sort_iter;
					sort_iter = sort_iter->next;
				}
				
				if(prev == NULL)  // Insert at beginning
				{
					sort_temp->next = sort_head_ptr;
					sort_head_ptr = sort_temp;
				}
				else  // Insert in middle or end
				{
					sort_temp->next = sort_iter;
					prev->next = sort_temp;
				}
			}
		}
		temp = temp->next;
	}
	
	// Display sorted view (temporary, not saved)
	printf("\n******************Sorted View (Not Saved)******************\n");
	printf("| Roll |        NAME        |    Department    |       Marks        |\n");
	printf("---------------------------------------------------------------------\n");
	
	ready *display_temp = sort_head_ptr;
	while(display_temp != NULL)
	{
		printf("  %-6d %-20s %-18s %.2f\n", display_temp->roll, display_temp->name, 
		       display_temp->department, display_temp->marks);
		printf("---------------------------------------------------------------------\n");
		display_temp = display_temp->next;
	}
	
	// Free sorted list (it was just for display)
	while(sort_head_ptr != NULL)
	{
		ready *temp_free = sort_head_ptr;
		sort_head_ptr = sort_head_ptr->next;
		free(temp_free);
	}
	
	char options;
	printf("\nEnter any key to return to menu: ");
	scanf(" %c", &options);
}

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

void reverse_print(ready *head_ptr)
{
	if(head_ptr == NULL)
	{
		printf("No records to display!\n");
		return;
	}
	
	// Count nodes (excluding deleted ones)
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
	
	// Create array to store pointers
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
	
	// Display in reverse (temporary view, not saved)
	printf("\n******************Reversed View (Not Saved)******************\n");
	printf("| Roll |        NAME        |    Department    |       Marks        |\n");
	printf("---------------------------------------------------------------------\n");
	
	for(int i = count - 1; i >= 0; i--)
	{
		printf("  %-6d %-20s %-18s %.2f\n", arr[i]->roll, arr[i]->name, 
		       arr[i]->department, arr[i]->marks);
		printf("---------------------------------------------------------------------\n");
	}
	
	free(arr);
	
	char options;
	printf("\nEnter any key to return to menu: ");
	scanf(" %c", &options);
}
