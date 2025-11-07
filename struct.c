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
void delete(ready *);
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
		printf("|                      V/v :      Save                         |\n");
		printf("|                      E/e :      Exit                         |\n");
		printf("|                      T/t :      Sort the list                |\n");
	      	printf("|                      L/l :      Delete all the record        |\n");
		printf("|                      R/r :      Reverse the list             |\n");
		printf("****************************************************************\n");

		printf("                      Enter the choice: ");	
		char options;
		scanf(" %c",&options);
				
		if(options == 'A' || options == 'a')
		{
			insert(&head_ptr);
		}
		else if(options == 'S'||options =='s')
		{
			display(head_ptr);
		}
		else if(options == 'D'|| options == 'd')
		{
			delete(head_ptr);		
		}
		else
		{
			if (options == 'E'|| 'e')
			{
				return 0;
			}
		}
			

	
		
			
			
	}
}
void delete(ready*temp)
{
	char dele_op;
      printf("\n|*************************Enter***********************|\n");
	printf("|		    R/r : Enter Roll no to delete     |\n");
	printf("|                   N/n : Enter the name to delete    |\n");
	printf("******************************************************\n");
	printf("Enter the choice: ");
	scanf(" %c",&dele_op);
	if(dele_op == 'R'|| dele_op == 'r')
	{
		int roll;
		printf("              Enter the roll no:");
		scanf("%d",&roll);
		if(temp->roll == roll)
		{
			strcpy(temp->name,"");
			
			strcpy(temp->department,"");
			temp->marks=0;
		}
		else
		{
			ready *temper=temp;
			while(temper->next!=NULL)
			{
				if(temper->roll == roll)
				{
					strcpy(temper->name,"");
					strcpy(temper->department,"");
					temper->marks=0;
				}
				
			}



		}
	}
	else if(dele_op =='N'|| dele_op =='n')
	{

		

	}
	


}
void display(ready *temp)
{
	int exit=0;
	printf("\n************************Student Details*****************************\n");
	printf("|roll |               NAME           |            Mark              |\n");
	printf("---------------------------------------------------------------------|\n");
	while(temp!=NULL)
	{
        printf("  %d                  %s                       %f               \n",temp->roll,temp->name,temp->marks);
	printf("--------------------------------------------------------------------\n");
		temp=temp->next;

	}
	char options='\0';
	printf("                     Enter any key to exit:");
	scanf(" %c",&options);
	if(options)
	{
		return;
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
	temp->roll=count;

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


		

