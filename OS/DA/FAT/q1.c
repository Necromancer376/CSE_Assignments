#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct process
{
    char name;
    int arv_tm, brst_tm, cmp_tm, wt_tm, trn_tm;
    int isComplete;
};


void Sort(int n, struct process proc[])
{
    struct process temp;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(proc[i].arv_tm > proc[j].arv_tm)
            {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}


void HRRN()
{
    int n;

    printf("n: ");
    scanf("%d", &n);

    int arv[n], brt[n];

    printf("Arival Time: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arv[i]);
    }

    printf("Burst Time: \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &brt[i]);
    }

    int total_bt = 0;
    float avg_wt = 0;
    float avg_tt = 0;
    char c;

    struct process proc[n];

    for(int i=0, c='A'; i<n; i++, c++)
    {
        proc[i].name = c;
        proc[i].arv_tm = arv[i];
        proc[i].brst_tm = brt[i];
        proc[i].isComplete = 0;

        total_bt += proc[i].brst_tm;
    }
    Sort(n, proc);
    printf("\nProc\tArival Time\tBurst Time\tWaiting Time\tTAT");
    for(int k = proc[0].arv_tm; k < total_bt;)
    {
        float h = -9999;
        float temp = 0;
        int loc;

        for(int i=0; i<n; i++)
        {
            if(proc[i].brst_tm <= k && proc[i].isComplete == 0)
            {
                temp = (proc[i].brst_tm + (k - proc[i].arv_tm)) / proc[i].brst_tm;
                if(h < temp)
                {
                    h = temp;
                    loc = i;
                }
            }
        }

        k += proc[loc].brst_tm;
        proc[loc].wt_tm = k - proc[loc].arv_tm - proc[loc].brst_tm;
        proc[loc].trn_tm = k - proc[loc].arv_tm;

        avg_tt += proc[loc].trn_tm;

        proc[loc].isComplete = 1;

        avg_wt += proc[loc].wt_tm;

        printf("\n%c\t%d\t\t\t%d\t\t%d\t\t%d", proc[loc].name, proc[loc].arv_tm, proc[loc].brst_tm, proc[loc].wt_tm, proc[loc].trn_tm);
    }

    printf("\nAvg Waiting Time = %f", avg_wt/n);
    printf("\nAvg Turn Around Time = %f", avg_tt/n);
}



int main(void)
{
    HRRN();

    printf("\n");
}