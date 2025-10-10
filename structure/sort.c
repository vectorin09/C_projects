#include<string.h>
#include<stdio.h>
#include"structure.h"
struct id  sort(struct id var[],int n)
{
        int f;
        printf("---How  can  i sort the details---\n1.Name\n2.marks \n" );
        scanf("%d",&f);

        if(f == 1)
        {

                for(int i=0;i<n;i++){
                        for(int j=0;j<=n-i-1;j++)
                                if(strcmp(var[j].name,var[j+1].name)>0)
                                {
                                        struct id temp=var[j+1];
                                        var[j+1]=var[j];
                                        var[j]=temp;
                                }

                }


	}
        else if(f == 2)
        {
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<=n-i-1;j++)
                        {
                                if(var[j].mark < var[j+1].mark)
                                {
                                        struct id temp = var[j+1];
                                        var[j+1]=var[j];
                                        var[j]=temp;

                                }
                        }
                }
        }
	 return var[0];

}

