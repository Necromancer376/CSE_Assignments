#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
    int d, m, y;
    int newd, newm, newy;
    scanf("%d%d%d", &m, &d, &y);
    printf("%d %d %d\n", d,m,y);

    int isLeap = 0;
    if((y % 4 == 0 || y % 100 == 0) && y % 400 != 0)
        isLeap = 1;

    if(d == 31 && m == 12)
        newy = y + 1;
    else
        newy = y;
    
    if(m != 12)
        newm = m + 1;
    else
        newm = 1;

    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if(d == 31)
            newd = 1;
        else
            newd = d + 1;
    }

    else if(m == 4 || m == 6 || m == 9 || m == 11)
    {
        if(d == 30)
            newd = 1;
        else
            newd = d + 1;
    }

    else
    {
        if(d <= 28 && isLeap == 1)
            newd = d + 1;
        else if(d < 28 && isLeap == 0)
            newd = d + 1;
        else
            newd = 1;
    }

    printf("Tomorrow's date is %d/%d/%d\n", newm, newd, newy);
}