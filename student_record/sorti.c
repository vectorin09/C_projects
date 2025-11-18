#include"header.h"
void sort(ready *head_ptr)
{
	if(head_ptr == NULL)
	{
		printf("No records to sort!\n");
		return;
	}
	
	ready *sort_head_ptr = NULL;	
	ready *temp = head_ptr;
		printf("\n");
	printf("_______________________________________________________\n");
	printf("|******************Requirements***********************|\n");
	printf("|            N/n : sort by name                       |\n");
	printf("|            P/p : sort by percentage                 |\n");
	printf("|_____________________________________________________|\n");
	printf("Enter the choice: ");
	char sort_op;
	scanf(" %c",&sort_op);
	
	
	if(sort_op == 'N'|| sort_op == 'n')
	{
		while(temp != NULL)
		{
			if(strcmp(temp->name, "") != 0)  
			{
				ready *sort_temp = (ready *)malloc(sizeof(ready));	
				strcpy(sort_temp->name, temp->name);
				sort_temp->marks = temp->marks;
				sort_temp->roll = temp->roll;
				sort_temp->next = NULL;
				
				if(sort_head_ptr == NULL)
				{
					sort_head_ptr = sort_temp;
				}
				else
				{
					ready *sort_iter = sort_head_ptr;
					ready *prev = NULL;
				
					
					while(sort_iter != NULL && strcmp(sort_temp->name, sort_iter->name) > 0)
					{
						prev = sort_iter;
						sort_iter = sort_iter->next;
					}
				
					if(prev == NULL)  
					{
						sort_temp->next = sort_head_ptr;
						sort_head_ptr = sort_temp;
					}
					else  
					{
						sort_temp->next = sort_iter;
						prev->next = sort_temp;
					}
				}
			}
			temp = temp->next;
		}
		printf("\n");
		printf("|******************Sorted View *****************|\n");
		printf("| Roll |        NAME        |      Marks        |\n");
		printf("|-----------------------------------------------|\n");
	
	
		ready *display_temp = sort_head_ptr;
		while(display_temp != NULL)
		{
			printf("|  %-6d %-20s  %.2f %11c\n", display_temp->roll, display_temp->name, 
		    	display_temp->marks,'|');
			printf("|-----------------------------------------------|\n");
			display_temp = display_temp->next;
		}
	
	
		while(sort_head_ptr != NULL)
		{
			ready *temp_free = sort_head_ptr;
			sort_head_ptr = sort_head_ptr->next;
			free(temp_free);
		}
	
		char options;
		printf("\nEnter any key to return to menu: ");
		scanf(" %c", &options);
		
	}
	else if(sort_op == 'P' || sort_op == 'p')
	{
		 while (temp != NULL)
		 {
        		if (strcmp(temp->name, "") != 0) 
			{
            			ready *sort_temp = (ready *)malloc(sizeof(ready));
            			strcpy(sort_temp->name, temp->name);
            			sort_temp->marks = temp->marks;
           			sort_temp->roll = temp->roll;
            			sort_temp->next = NULL;
			

            			if (sort_head_ptr == NULL) 
				{
                			sort_head_ptr = sort_temp;
            			} 
				else 
				{
                			ready *sort_iter = sort_head_ptr;
                			ready *prev = NULL;

              
                			while (sort_iter != NULL && sort_temp->marks < sort_iter->marks) 
					{
                    			prev = sort_iter;
                    			sort_iter = sort_iter->next;
               		 		}
	
                			if (prev == NULL) 
					{
                  
                    			sort_temp->next = sort_head_ptr;
                    			sort_head_ptr = sort_temp;
                			} 
					else 
					{
               
                    			sort_temp->next = sort_iter;
                    			prev->next = sort_temp;
                			}
            			}	
        		}
        	temp = temp->next;
    		}


    		printf("\n");
		printf("|******************Sorted View *****************|\n");
		printf("| Roll |        NAME        |      Marks        |\n");
		printf("|-----------------------------------------------|\n");
	
    		ready *display_temp = sort_head_ptr;
    		while (display_temp != NULL)
		 {
        		printf("|  %-6d %-20s  %.2f %11c\n", display_temp->roll, display_temp->name, 
		    	display_temp->marks,'|');
			printf("|-----------------------------------------------|\n");
			display_temp = display_temp->next;
    		}

  
    		while (sort_head_ptr != NULL)
	 	{
        		ready *temp_free = sort_head_ptr;
        		sort_head_ptr = sort_head_ptr->next;
        		free(temp_free);
    		}

    		char options;
    		printf("\nEnter any key to return to menu: ");
    		scanf(" %c", &options);
		
	}
}
