#include<stdio.h>
#include"structure.h"

void display_student_details()
{
	char charcter_array[100];
	int line_length=100;
	FILE*file_to_display=fopen("database.txt","r");
	while(fgets(charcter_array,line_length,file_to_display)!=NULL)
	{
		printf("  %s\n",charcter_array);
	}

}

