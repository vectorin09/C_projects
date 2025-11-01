#include<stdio.h>
#include<string.h>
typedef struct student
{
	char department[8];
     	int roll;
	float marks;
	struct student *next;
}ready;

ready *ECE;
ready *MECH;
ready *EEE;
ready *CSE;
ready *CIVIL;

int main()
{
	while(1)
	{
		char  op;
		scanf(" %c",&op);
		if(op =='y')
		{
			ready temp;
			printf("Enter the student department: ");
			scanf("%s",temp.department);
			printf("Enter the roll number: ");
			scanf("%d",&temp.roll);
			printf("Enter the marks : ");
			scanf("%f",&temp.marks);
			temp.next=NULL;
			if(strcmp(temp.department, "ECE")==0)
			{
				if (ECE == NULL)
				{
					ECE = &temp;
				}
				else
				{
					temp.next=ECE;
					ECE=&temp;
					
				}
			}

			
		}
		else if(op == 'd')
		{
			ready *temp=ECE;
			while((*temp).next !=NULL)
			{
				printf("%d",ECE->roll);
				temp=ECE->next;
			}
		}
		else
		{
			return 0;
		}
	}
}
