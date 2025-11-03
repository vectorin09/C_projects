#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char department[8];
	char name[20];
     	int roll;
	float marks;
	struct student *next;
}ready;

void depart_separation(ready **,int,int);


ready *ECE;
ready *MECH;
ready *EEE;
ready *CSE;
ready *CIVIL;

void display();
void insert();
void save_database();  

int roll_number_generator;

int main()
{
	while(1)
	{
		int  op;
		scanf("%d",&op);
		if(op == 1)
			insert();
		else if(op == 2)
			display();
		else if(op == 3)
			save_database();
		else
			return 0;
			
	}
}
void display()
{
	char buffer;
	FILE*file=fopen("data_base.txt","r");
	while((buffer=fgetc(file))!=EOF)
		printf("%c",buffer);


}
void insert()
{
	int depart;

	printf("1.ECE\n2.MECH\n3.CIVIL\n4.EEE\nEnter the student department: ");


	scanf("%d",&depart);

	if(depart == 1)
	{
		++roll_number_generator;
		depart_separation(&ECE,roll_number_generator,depart);
	}
	else if(depart == 2)
	{

		++roll_number_generator;
		depart_separation(&MECH,roll_number_generator,depart);
	}
	else if(depart == 3)
	{
				
		++roll_number_generator;
		depart_separation(&CIVIL,roll_number_generator,depart);
	}
	else if(depart == 4)
	{
		
		++roll_number_generator;
		depart_separation(&EEE,roll_number_generator,depart);
	}
	else
		return;


		
}
void depart_separation(ready **depart_ptr,int roll,int op)
{

	ready *temp =(ready *)malloc(sizeof(ready));

	temp->roll=roll;

	if (op ==1)strcpy(temp->department,"ECE");
	else if (op ==2)strcpy(temp->department,"MECH");
	else if (op ==3)strcpy(temp->department,"CIVIL");
	else if (op ==4)strcpy(temp->department,"EEE");
	else 
		return;	
	
	
	

	printf("Enter the name of the student: ");
	scanf("%s",temp->name);

	printf("\nEnter the marks : ");

	scanf("%f",&(*temp).marks);

	if(*depart_ptr ==NULL)
	{
		*depart_ptr=temp;
		temp->next=NULL;
	}
	else
	{
		ready *iter=*depart_ptr;
		while(iter->next!=NULL)
		{
			iter=iter->next;
		}
		iter->next=temp;
		temp->next=NULL;

	}
	save_database(temp);


}

void save_database(ready*details)
{
	FILE*file=fopen("data_base.txt","a");
	if(file == NULL)
	{
		printf("the file was not available do u want me to create one\n");
		printf("creating ... \n");
		printf("file was successfuly created..\n");
		file=fopen("data_base.txt","w");
		file=fopen("data_base.txt","a");
		fprintf(file,"rollno         name         mark ");
		return;
	}
	fprintf(file,"%d  ",details->roll);
	fprintf(file,"%s  ",details->name);
	fprintf(file,"%s ",details->department);
	fprintf(file,"%f  \n",details->marks);
	fclose(file);
}
