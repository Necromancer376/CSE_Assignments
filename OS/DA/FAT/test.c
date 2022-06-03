#include <stdio.h>
 
struct process {
    char name;
    int at, bt, ct, wt, tt;
    int completed;
    float ntt;
} p[10];
 
int n;


void sortByArrival()
{
    struct process temp;
    int i, j;
 

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
 
            if (p[i].at > p[j].at) {
 
                // Swap earlier process to front
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
 
void main()
{
    int i, j, t, sum_bt = 0;
    char c;
    float avgwt = 0, avgtt = 0;
 
    // predefined arrival times

    printf("n: ");
    scanf("%d", &n);

    int arriv[n], burst[n];

    printf("Arival Time: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arriv[i]);
    }

    printf("Burst Time: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &burst[i]);
    }
    // Initializing the structure variables
    for (i = 0, c = 'A'; i < n; i++, c++) {
        p[i].name = c;
        p[i].at = arriv[i];
        p[i].bt = burst[i];
 
        // Variable for Completion status
        // Pending = 0
        // Completed = 1
        p[i].completed = 0;
 
        // Variable for sum of all Burst Times
        sum_bt += p[i].bt;
    }
 
    // Sorting the structure by arrival times
    sortByArrival();
    printf("\nName\tArrival Time\tBurst Time\tWaiting Time");
    printf("\tTurnAround Time");
    for (t = p[0].at; t < sum_bt;) {
 
        // Set lower limit to response ratio
        float hrr = -9999;
 
        // Response Ratio Variable
        float temp;
 
        // Variable to store next process selected
        int loc;
        for (i = 0; i < n; i++) {
 
            // Checking if process has arrived and is Incomplete
            if (p[i].at <= t && p[i].completed != 1) {
 
                // Calculating Response Ratio
                temp = (p[i].bt + (t - p[i].at)) / p[i].bt;
 
                // Checking for Highest Response Ratio
                if (hrr < temp) {
 
                    // Storing Response Ratio
                    hrr = temp;
 
                    // Storing Location
                    loc = i;
                }
            }
        }
 
        // Updating time value
        t += p[loc].bt;
 
        // Calculation of waiting time
        p[loc].wt = t - p[loc].at - p[loc].bt;
 
        // Calculation of Turn Around Time
        p[loc].tt = t - p[loc].at;
 
        // Sum Turn Around Time for average
        avgtt += p[loc].tt;
 
        // Calculation of Normalized Turn Around Time
 
        // Updating Completion Status
        p[loc].completed = 1;
 
        // Sum Waiting Time for average
        avgwt += p[loc].wt;
        printf("\n%c\t\t%d\t\t", p[loc].name, p[loc].at);
        printf("%d\t\t%d\t\t", p[loc].bt, p[loc].wt);
        printf("%d\t\t", p[loc].tt);
    }
    printf("\nAverage waiting time:%f\n", avgwt / n);
    printf("Average Turn Around time:%f\n", avgtt / n);
}