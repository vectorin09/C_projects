#include<stdio.h>
#include"structure.h"
struct id  insert(struct id in[],int n)
{
        for(int i=0;i<n;i++){
        

                printf("Enter the values of struct [%d]",i+1);
                scanf("%s %f",in[i].name,&in[i].mark);
	}
	return in[0];

        
}

