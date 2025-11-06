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
void delete(ready **,int);
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
		{
			int spc ,roll;
			printf("Enter which department student details which you want to delete \n 1.ECE 2.MECH 3.EEE 4.CIVIL\n");
			scanf("%d %d" ,&spc,&roll);
			switch(spc)
			{
				case 1:delete(&ECE,roll);
				       break;
				case 2:delete(&MECH,roll);
				       break;
				case 3:delete(&EEE,roll);
			       		break;
				case 4:delete(&CIVIL,roll);
				       break;
				default:
				       printf("Entered an wrong department");
			}
		}
		else
			return 0;
			
	}
}
void delete(ready **node,int roll)
{
	ready *ptr=*node;
	ready *temp=*node;
	while(ptr->next!=NULL)
	{
		if((ptr->roll == roll))
		{
			ptr->department[0]='\0';
			ptr->name[0]='\0';
			ptr->marks=0;
	
		}
		ptr=ptr->next;
	}
	printf("After the deletions of the details \n the students int the departments are \n");
	while(temp->next !=NULL)
	{
		printf("%d %s %s %f\n",temp->roll,temp->name,temp->department,temp->marks);
		temp=temp->next;
	}


}
void display()
{
	int count=0;
	char buffer;
	FILE*file=fopen("data_base.txt","r");
	while((buffer=fgetc(file))!=EOF)
	{
	
		printf("%c",buffer);
	}


}
void insert()
{
	int depart;

	char buffer;

	int count=1;
	FILE*fp=fopen("data_base.txt","r");
	if(fp != NULL)
	{
		while(((buffer=getc(fp))!=EOF))
		{	
			if(buffer == '\n')
			{
				count++;
			}

		}
	}

	printf("1.ECE\n2.MECH\n3.CIVIL\n4.EEE\nEnter the student department: ");


	scanf("%d",&depart);

	if(depart == 1)
	{
		depart_separation(&ECE,count,depart);
	}
	else if(depart == 2)
	{

		++roll_number_generator;
		depart_separation(&MECH,count,depart);
	}
	else if(depart == 3)
	{
				
		++roll_number_generator;
		depart_separation(&CIVIL,count,depart);
	}
	else if(depart == 4)
	{
		
		++roll_number_generator;
		depart_separation(&EEE,count,depart);
	}
	
	else
		printf("rady %d",count);


		
}
void depart_separation(ready **ece_ptr,int roll,int op)
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
