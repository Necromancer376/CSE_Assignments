#include<stdio.h>
#include<stdlib.h>


void FirstFit(int n_blocks, int n_proc, int memory[], int proc[])
{
    int alloc[n_proc];
    for(int i=0; i<n_proc; i++)
    {
        alloc[i] = -1;
    }

    for(int i=0; i<n_proc; i++)
    {
        for(int j=0; j<n_blocks; j++)
        {
            if(proc[i] <= memory[j])
            {
                alloc[i] = j;
                memory[j] -= proc[i];
                break;
            }
        }
    }
    for(int i=0; i<n_proc; i++)
    {
        if(alloc[i] != -1)
            printf("proc %d -> block %d\n", i, alloc[i]);
        else
            printf("cannot allocate proc %d\n", i);
    }
}


void BestFit(int n_blocks, int n_proc, int memory[], int proc[])
{
    int alloc[n_proc];
    for(int i=0; i<n_proc; i++)
    {
        alloc[i] = -1;
    }

    for(int i=0; i<n_proc; i++)
    {
        int best = -1;
        for(int j=0; j<n_blocks; j++)
        {
            if(memory[j] >= proc[i])
            {
                if(best == -1)
                    best = j;
                else if(memory[best] > memory[j])
                    best = j;
            }
        }

        if(best != -1)
        {
            alloc[i] = best;
            memory[best] -= proc[i];
        }

    }

    for(int i=0; i<n_proc; i++)
    {
        if(alloc[i] != -1)
            printf("proc %d -> block %d\n", i, alloc[i]);
        else
            printf("cannot allocate proc %d\n", i);
    }
}


void WorstFit(int n_blocks, int n_proc, int memory[], int proc[])
{
    int alloc[n_proc];
    for(int i=0; i<n_proc; i++)
    {
        alloc[i] = -1;
    }

    for(int i=0; i<n_proc; i++)
    {
        int worst = -1;
        for(int j=0; j<n_blocks; j++)
        {
            if(memory[j] >= proc[i])
            {
                if(worst == -1)
                    worst = j;
                else if(memory[worst] < memory[j])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            alloc[i] = worst;
            memory[worst] -= proc[i];
        }
    }
    
    for(int i=0; i<n_proc; i++)
    {
        if(alloc[i] != -1)
            printf("proc %d -> block %d\n", i, alloc[i]);
        else
            printf("cannot allocate proc %d\n", i);
    }
}


int main()
{
    int n_blocks, n_proc;
    printf("no. blocks: ");
    scanf("%d", &n_blocks);
    int memory[n_blocks], memory1[n_blocks], memory2[n_blocks];

    printf("block size:\n");
    for(int i=0; i<n_blocks; i++)
    {
        int x;
        scanf("%d", &x);
        memory[i] = x;
        memory1[i] = x;
        memory2[i] = x;
    }

    printf("no. proc: ");
    scanf("%d", &n_proc);
    int proc[n_proc], proc1[n_proc], proc2[n_proc];;
    printf("processes:\n");
    for(int i=0; i<n_proc; i++)
    {
        int x;
        scanf("%d", &x);
        proc[i] = x;
        proc1[i] = x;
        proc2[i] = x;
    }

// First Fit
    printf("\nFirstFit: \n");
    FirstFit(n_blocks, n_proc, memory, proc);

// Best Fit
    printf("\nBestFit: \n");
    BestFit(n_blocks, n_proc, memory1, proc1);

// Worst Fit
    printf("\nWorstFit: \n");
    WorstFit(n_blocks, n_proc, memory2, proc2);
}