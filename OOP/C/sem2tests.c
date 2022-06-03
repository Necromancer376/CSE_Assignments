#include<stdio.h>
#include<string.h>

struct student
{
    int id,marks;
    char name[25], batch[25];
}stud[100],t;
 
int main()
{
    int i,j,n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    printf("Enter student info as Name,ID,Batch,Marks\n");
    for(i=0;i<n;i++)
    {
     scanf(" %s %d %s %d", stud[i].name, &stud[i].id, stud[i].batch, &stud[i].marks);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(stud[j].marks<stud[j+1].marks)
            {
                t=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=t;
            }
        }
    }
    
    printf("Details of the student with highest marks:\n");
    printf("\nNAME\t\tID\t\tBATCH\n");
    printf("-------------------------------------------------------------------------------\n");
    
    printf("%s\t\t\t%d\t\t\t%s\n", stud[0].name, stud[0].id, stud[0].batch);
}