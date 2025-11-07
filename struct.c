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




ready *head_ptr;

int count=0;
void display(ready*);
void delete();
void insert(ready **);
void save_database();  

int main()
{
	while(1)
	{



		printf("\n******************************STUDENT RECORD*******************\n");
		printf("|                      A/a :      Add a new record             |\n");
		printf("|                      D/d :      Delete a record              |\n");
		printf("|                      S/s :      Show the list                |\n");
		printf("|                      A/a :      Modifiy the record           |\n");
		printf("|                      D/d :      Delete a record              |\n");
		printf("|                      V/v :      Save                         |\n");
		printf("|                      E/e :      Exit                         |\n");
		printf("|                      T/t :      Sort the list                |\n");
	      	printf("|                      L/l :      Delete all the record        |\n");
		printf("|                      R/r :      Reverse the list             |\n");
		printf("****************************************************************\n");

		printf("                      Enter the choice: ");	
		char options;
		scanf("%c",&options);
				
		if(options == 'A' || options == 'a')

			insert(&head_ptr);
		else if(options == 'S'||options =='s')
			display(head_ptr);
		else if(options == 'D'|| options == 'd')
		{
			delete();		
		}
		else
			return 0;
		
			
			
	}
}
void delete()
{
	char dele_op;
	printf("\n********************Enter **************************\n");
	printf("|		    R/r : Enter Roll no to delete    |\n");
	printf("|                   N/n : Ente the name to delete    |\n");
	printf("******************************************************\n");
	printf("Enter the choice: ");
	scanf("%c",&dele_op);
	if(dele_op == 'R'|| dele_op == 'r')
	{

	}
	else if(dele_op =='N'|| dele_op =='n')
	{

	}
	else
		return;


}
void display(ready *temp)
{
	int exit=0;
	printf("\n************************Student Details********************************\n");
	while(temp!=NULL)
	{
		printf("-------------------------------------------------------------------\n");
		printf("                  %s            |            %f                    \n",temp->name,temp->marks);
		printf("--------------------------------------------------------------------\n");
		temp=temp->next;

	}
	
	printf("                Press any key to exit: ");
	scanf("%d",&exit);
	while(1)
	{	
		if(exit)
		{
			return;
		}
	}
}

void insert(ready**head_ptr)
{
	count++;
	ready *temp=(ready *)malloc(sizeof(ready));
	printf("----------------------------------------------\n");
	printf("               Enter The Student Name: ");
	scanf("%s" ,temp->name);
	printf("-----------------------------------------------\n");
	printf("1.ECE \n 2.MECH \n 3.EEE \n 4.CIVIL \n");
	printf("               Enter The Department: ");
	scanf("%s",temp->department);
	printf("------------------------------------------------\n");
	printf("               Enter The Marks: ");
	scanf("%f",&temp->marks);

	if(*head_ptr==NULL)
	{
		*head_ptr=temp;
		temp->next=NULL;
	}
	else
	{
		ready *temper=*head_ptr;
		while(temper->next!=NULL)
		{
			temper=temper->next;
		}
		temper->next=temp;

	}
	
	
}


		


