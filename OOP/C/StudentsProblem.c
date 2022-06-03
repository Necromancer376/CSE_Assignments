#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student
{
    char name[50];
    int rollNo;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int total;
    int avg;
    char class[50];
    char isPass[4];
};


int main(void)
{
    int n;
    scanf("%d", &n);
    struct student s[n];

    for(int i=0; i<n; i++)
    {
        struct student input;   

        scanf("%s%d%d%d%d%d%d", input.name, &input.rollNo, &input.m1, &input.m2, &input.m3, &input.m4, &input.m5);

        s[i] = input;

        s[i].total = s[i].m1 + s[i].m2 + s[i].m3 + s[i].m4 + s[i].m5;
        s[i].avg = s[i].total / 5;

        if(s[i].m1 <40 || s[i].m2 <40 || s[i].m3 <40 || s[i].m4 <40 || s[i].m5 < 40)
            strcat(s[i].isPass, "Fail");
        else
            strcat(s[i].isPass, "Pass");

        if(s[i].avg >=75)
            strcat(s[i].class, "Distiction");
        else if(s[i].avg >= 60)
            strcat(s[i].class, "First Class");
        else if(s[i].avg >= 50)
            strcat(s[i].class, "Second Class");
        else
            strcat(s[i].class, "");
    }

    for(int i=0; i<n; i++)
    {
        printf("Mark Sheet\n");
        printf("Name of Student:%s\n", s[i].name);
        printf("Roll No:%d\n", s[i].rollNo);
        printf("-------------\n");
        printf("Subject 1:%d\n", s[i].m1);
        printf("Subject 2:%d\n", s[i].m2);
        printf("Subject 3:%d\n", s[i].m3);
        printf("Subject 4:%d\n", s[i].m4);
        printf("Subject 5:%d\n", s[i].m5);
        printf("-------------\n");
        printf("Total Marks:%d\n", s[i].total);
        printf("Average Marks:%d\n", s[i].avg);
        printf("Class:%s\n", s[i].class);
        printf("Status:%s\n", s[i].isPass);
        printf("\n\n");
    }
}