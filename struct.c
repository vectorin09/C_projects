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

void ece_depart(ready **,int);
void mech_depart(ready **,int);
void eee_depart(ready **,int);
void civil_depart(ready **,int);

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
		ece_depart(&ECE,roll_number_generator);
	}
	else if(depart == 2)
	{

		++roll_number_generator;
		mech_depart(&MECH,roll_number_generator);
	}
	else if(depart == 3)
	{
				
		++roll_number_generator;
		civil_depart(&CIVIL,roll_number_generator);
	}
	else if(depart == 4)
	{
		
		++roll_number_generator;
		eee_depart(&EEE,roll_number_generator);
	}
	else
		return;


		
}
void ece_depart(ready **ece_ptr,int roll)
{

	ready *temp =(ready *)malloc(sizeof(ready));

	temp->roll=roll;

	strcpy(temp->department,"ECE");
	
	
	

	printf("Enter the name of the student: ");
	scanf("%s",temp->name);

	printf("\nEnter the marks : ");

	scanf("%f",&(*temp).marks);

	if(*ece_ptr ==NULL)
	{
		*ece_ptr=temp;
		temp->next=NULL;
	}
	else
	{
		ready *iter=*ece_ptr;
		while(iter->next!=NULL)
		{
			iter=iter->next;
		}
		iter->next=temp;
		temp->next=NULL;

	}
	save_database(temp);


}

void mech_depart(ready **mech_ptr,int roll)
{

	ready *temp =(ready *)malloc(sizeof(ready));

	temp->roll=roll;
	
	strcpy(temp->department,"MECH");

	printf("Enter the name of the student: ");
	scanf("%s",temp->name);


	printf("\nEnter the marks : ");

	scanf("%f",&(*temp).marks);

	if(*mech_ptr ==NULL)
	{
		*mech_ptr=temp;
		temp->next=NULL;
	}
	else
	{
		ready *iter=*mech_ptr;
		while(iter->next!=NULL)
		{
			iter=iter->next;
		}
		iter->next=temp;
		temp->next=NULL;

	}

	save_database(temp);

}

void eee_depart(ready **eee_ptr,int roll)
{

	ready *temp =(ready *)malloc(sizeof(ready));

	temp->roll=roll;
	
	printf("Enter the name of the student: ");
	scanf("%s",temp->name);
	
	strcpy(temp->department,"EEE");
	printf("\nEnter the marks : ");

	scanf("%f",&(*temp).marks);

	if(*eee_ptr ==NULL)
	{
		*eee_ptr=temp;
		temp->next=NULL;
	}
	else
	{
		ready *iter=*eee_ptr;
		while(iter->next!=NULL)
		{
			iter=iter->next;
		}
		iter->next=temp;
		temp->next=NULL;

	}


	save_database(temp);
}

void civil_depart(ready **civil_ptr,int roll)
{

	ready *temp =(ready *)malloc(sizeof(ready));

	temp->roll=roll;

	strcpy(temp->department,"CIVIL");
	
	printf("Enter the name of the student: ");
	scanf("%s",temp->name);


	printf("\nEnter the marks : ");

	scanf("%f",&(*temp).marks);

	if(*civil_ptr ==NULL)
	{
		*civil_ptr=temp;
		temp->next=NULL;
	}
	else
	{
		ready *iter=*civil_ptr;
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
