#include<stdio.h>
#include"structure.h"
int number_of_student;
struct id global_var[];

int main()
{
	int start_option;
	printf("1.Are you want to insert the details\n2.Want to sort the data\n3.display details\n4.For search student details\n");
	scanf("%d",&start_option);
	if(start_option == 1)
	{
		printf("-------------how many student record do you want to save-------  ");
		scanf("%d",&number_of_student);
		
		//Created the structure for storing the details
		struct id global_var[number_of_student];				
		insert(global_var,number_of_student);
		//Save it on file called database.txt
		char save;
		printf("-----Please save it on file-----press c\n");
		scanf(" %c",&save);
		if(save == 'c'|save == 'C') file(global_var,number_of_student);

	}
	else if(start_option == 2)
	{
		printf("1.for sort\n0.No need sort\n");
		
		int  option_for_sorting;
		
		scanf("%d",&option_for_sorting);
		
		if(option_for_sorting){
		
			sort(global_var,number_of_student);
		}
	}
	else if(start_option == 3)
	{
		printf("\n--student name --student marks\n");
		display_student_details();

	}
	else if(start_option == 4)
		search_for_student();
        printf("\n------------------------Thanks for reaching us ------------------------\n");
	

	
}



