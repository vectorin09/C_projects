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

int count=1;
int delete_flag=0;
void display(ready*);
void delete(ready *);
void insert(ready **);  
void mod(ready *);
void save(ready*);
void sort(ready *);
int fun_exit();
void reverse_print();


void display_from_file(void);
int display_file_flag=1;
void sort_from_file(void);


int main()
{
	while(1)
	{



		printf("\n******************************STUDENT RECORD*******************\n");
		printf("|                      A/a :      Add a new record             |\n");
		printf("|                      D/d :      Delete a record              |\n");
		printf("|                      S/s :      Show the list                |\n");
		printf("|                      M/m :      Modifiy the record           |\n");
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
		else if(options =='M'|| options == 'm')
		{
			mod(head_ptr);
		}
		else if(options == 'V'|| options == 'v' )
		{
			save(head_ptr);
		}
		else if(options == 'T'||options == 't')
		{
			sort(head_ptr);
		}
		else
		{
			if (options == 'E'|| 'e')
			{
				int op =fun_exit();
				if(op == 1|| op==0)
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
	printf("******************************************************|\n");
	printf("Enter the choice: ");
	scanf(" %c",&dele_op);

	if(dele_op == 'R'|| dele_op == 'r')
	{
		int roll;
		printf("Enter the roll no:");
		scanf("%d",&roll);
		if(temp->roll == roll)
		{
			delete_flag++;
			strcpy(temp->name,"");
			strcpy(temp->department,"");
			temp->marks=0;
		}
		else
		{
			ready *temper=temp;
			while(temper!=NULL)
			{
				if(temper->roll == roll)
				{
					delete_flag++;
					strcpy(temper->name,"");
					strcpy(temper->department,"");
					temper->marks=0;

				}
				temper=temper->next;
				
			}



		}

	}
	else if(dele_op =='N'|| dele_op =='n')
	{
		char check_str[20];
		printf("Enter the name:");
		scanf("%s",check_str);
		if(strcmp(temp->name,check_str)==0)
		{
			delete_flag++;
			strcpy(temp->name,"");
			strcpy(temp->department,"");
			temp->marks=0;
		}
		else
		{
			
			ready *temper=temp;
			while(temper!=NULL)
			{
				if(strcmp(temper->name,check_str)==0)
				{
					delete_flag++;
					strcpy(temper->name,"");
					strcpy(temper->department,"");
					temper->marks=0;
				}
				temper=temper->next;
			}


		

		}
	}

	


}
void display(ready *temp)
{
	int exit=0;
	if(display_file_flag)
	{
		display_from_file();
		return;
	}
	printf("\n************************Student Details*****************************\n");
	printf("|roll |               NAME           |            Mark              |\n");
	printf("---------------------------------------------------------------------\n");
	while(temp!=NULL)
	{
        printf("  %d                  %s                                  %f\n",temp->roll,temp->name,temp->marks);
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
	
	printf("%d",delete_flag);
	display_file_flag=0;
	char buffer;
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
	ready *temp=(ready *)malloc(sizeof(ready));
	printf("----------------------------------------------\n");
	printf("               Enter The Student Name: ");
	scanf("%s" ,temp->name);
	printf("------------------------------------------------\n");
	printf("               Enter The Marks: ");
	scanf("%f",&temp->marks);
	temp->roll=count;
	temp->next=NULL;
	count++;
	if(count && delete_flag)
	{
		ready*ptr=*head_ptr;
		
		while(ptr->next!=NULL)
		{
			if(strcmp(ptr->name,"")==0)
			{
				
				strcpy(ptr->name,temp->name);
				ptr->marks=temp->marks;
			}
			ptr=ptr->next;
		}
		delete_flag--;

	}

	else if(*head_ptr==NULL)
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
void mod(ready*head_ptr)
{
	
      printf("\n|*************************Requirments*****************|\n");
	printf("|		    N/n : search by name              |\n");
	printf("|                   P/p : search by percentage        |\n");
	printf("|                   R/r : search by roll              |\n");
	printf("******************************************************|\n");
	printf("Enter the choice: ");
	char op;
	scanf(" %c",&op);
	ready*temp=head_ptr;
	if(op == 'N'|| op == 'n')
	{
		char name[20];
		printf("Enter the name to be find ");
		scanf("%s",name);
		while(temp->next!=NULL)
		{
			if(strcmp(name,temp->name)==0)
			{
				char mod_op;
			
      				printf("\n|*************************Requirments*****************|\n");
				printf("|		    N/n : change the  name              |\n");
				printf("|                   P/p : change the percentage         |\n");
				printf("******************************************************* |\n");
				scanf(" %c",&mod_op);
				if(mod_op == 'N' ||mod_op =='n' )
				{
					char name[20];
					printf("Enter the name :");
					scanf("%s",name);
					strcpy(temp->name,name);
				}
				else if(mod_op == 'P' ||mod_op =='p' )
				{
					float mark;
					printf("Enter the percentage");
					scanf("%f",&mark);
					temp->marks=mark;
				}


			}
			temp=temp->next;
		}
	}
	else if(op == 'R'|| op == 'r')
	{
		int mod_roll;
		printf("Enter the roll no to be find ");
		scanf("%d",&mod_roll);
		while(temp!=NULL)
		{
			printf("checking......\n");
			if(temp->roll == mod_roll)
			{
				printf("checking2.......\n");
				char mod_op;
			
      				printf("\n|*************************Requirments*****************|\n");
				printf("|		    N/n : change the  name              |\n");
				printf("|                   P/p : change the percentage         |\n");
				printf("******************************************************* |\n");
				scanf(" %c",&mod_op);	
				if(mod_op == 'N' ||mod_op =='n' )
				{
					char name[20];
					printf("Enter the name :");
					scanf("%s",name);
					strcpy(head_ptr->name,name);
				}
				else if(mod_op == 'P' ||mod_op =='p' )
				{
					float mark;
					printf("Enter the percentage");
					scanf("%f",&mark);
					temp->marks=mark;
				}
			
						
				

			}
			temp=temp->next;

		}
	}


		
}
int save_flag=1;
void save(ready*head_ptr)
{
	save_flag=0;
	ready*temp=head_ptr;
	while(temp!=NULL)
	{
		FILE*file=fopen("data_base.txt","a");
		fprintf(file,"%d  ",temp->roll);
		fprintf(file,"%s  ",temp->name);
		fprintf(file,"%f  \n",temp->marks);
		fclose(file);
		temp=temp->next;
	}

}
void sort(ready *head_ptr)
{
	ready *temp=(ready*)malloc(sizeof(ready));
	temp=head_ptr;
	ready *sort_head_ptr=NULL;	
	printf("\n************************After sorting********************\n");
	printf("\n----------------------------------------------------------\n");
	while(temp!=NULL)
	{
		ready *sort_temp=(ready*)malloc(sizeof(ready));	
		strcpy(sort_temp->name,temp->name);
		sort_temp->marks=temp->marks;
		sort_temp->roll=temp->roll;
		sort_temp->next=NULL;
		if(sort_head_ptr==NULL)
		{
			sort_head_ptr=sort_temp;
		}
		else
		{
			
			ready *sort_iter_header_ptr= sort_head_ptr;
			while(sort_iter_header_ptr->next!=NULL)
			{
				if((sort_temp->name[0] < sort_iter_header_ptr->name[0]) && (sort_iter_header_ptr == sort_head_ptr))
					break;
				else if((sort_temp->name[0] > sort_iter_header_ptr->name[0]) && (sort_temp->name[0]< sort_iter_header_ptr->next->name[0]))
					break;
				
				sort_iter_header_ptr=sort_iter_header_ptr->next;

			}
			if(sort_iter_header_ptr == sort_head_ptr)
			{
				sort_temp->next=sort_iter_header_ptr;
				sort_head_ptr=sort_temp;
			}
			else
			{
				sort_temp->next=sort_iter_header_ptr->next;
				sort_iter_header_ptr->next=sort_temp;

			}
		}
			temp=temp->next;
		
	}
	
	display(sort_head_ptr);
}
int fun_exit()
{
	if(save_flag)
	{
		char op;
		printf("**************************************************************************************************");
		printf("\nE/e:Exit  without saving the file \nV/v Exit with saving the file  \n****************************************************************************************\n                 Enter the choices:");
		scanf(" %c",&op);
		if(op == 'v'|| op == 'V')
		{
			save(head_ptr);
			printf("\n******************************saved sucessfully********************************\n");
			return 0;
		}
		else
			return 0;
	}
	else
		return 1;
}
void display_from_file()
{
	
		char buffer[20];
		int co=0;
		FILE*file_open=fopen("data_base.txt","r");
		printf("\n************************Student Details*****************************\n");
		printf("|roll |               NAME           |            Mark              |\n");
		printf("---------------------------------------------------------------------\n");
	
		while(fscanf(file_open,"%s",buffer)!=EOF)
		{
		
			printf("  %s                            ",buffer);
			co++;
			if(co==3)
			{
				printf("\n");
				printf("-------------------------------------------------------------------\n");
				co=0;
			}
		}
		

	
	
	
}
