#include<stdio.h>
#include"insert.c"
#include"sort.c"
#include<string.h>
struct id{
	char name[20];
	float mark;
};



int file(struct id[],int);


int main()
{
	printf("-------------how many student record do you want to save-------  ");int y;
	scanf("%d",&y);
	
	struct id f[y];
	insert(f,y);
	file(f,y);
	printf("-----------Are you need to sort or not----------\n1.for sort\n0.No need sort\n");
	int  u;scanf("%d",&u);
	if(u)
		sort(f,y);

	
}


int file(struct id a[],int data_length)
{
	int option;printf("----------what do you want-------\n1.To clear the data\n2.append the data\n3.To update the student details\n");
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


