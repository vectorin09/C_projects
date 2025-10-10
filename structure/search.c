#include<stdio.h>
#include<string.h>
#include"structure.h"
void search_for_student()
{
	char student_name[25];
	//Getting the information from the user on runtime
	printf("Enter the student Name to find\n ");
	scanf("%s",student_name);

	FILE *file_to_search=fopen("database.txt","r");
	int flag=0;
	int line_length =50;

	char get_array[line_length];
	while(fgets(get_array,line_length,file_to_search)!=NULL)
	{
		if(strstr(get_array,student_name)!=NULL){
			printf("\nthe student %s details\n%s",student_name,get_array);
			flag=1;
		}
	}
	if(flag == 0) 
	{
		printf("\n!Error the student record is not found!\n");
	}
}
