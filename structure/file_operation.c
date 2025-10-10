#include<stdio.h>
#include<string.h>
#include"structure.h"
int file(struct id a[],int data_length)
{
	int option;printf("----------what do you want-------\n1.To clear the student previous data  and then update \n2.append the student data\n3.To search student details\n");
       	scanf("%d",&option);

	if (option == 1)
	{
		FILE*file=fopen("database.txt","w");
		for(int i=0;i<data_length;i++)
		{

			fprintf(file,"%s %f\n",a[i].name,a[i].mark);
		
		}
		fclose(file);
	}
	else if(option == 2){ 
		for(int b=0;b<data_length;b++)
		{	
		FILE*file_to_append=fopen("database.txt","a+"); 
		fprintf(file_to_append,"%s %f\n",a[b].name,a[b].mark);
		fclose(file_to_append);
		}
	}
	

	printf("\n");
}


