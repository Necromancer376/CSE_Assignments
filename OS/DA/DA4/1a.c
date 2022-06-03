#include <stdio.h>
#include <stdlib.h>


int FIFO(int ref[], int f, int p, int frames)
{
      int temp[frames];
      for(int i=0; i<frames; i++)
      {
            temp[i] = -1;
      }

      for(int i=0; i<p; i++)
      {
            int s = 0;
            for(int j=0; j<frames; j++)
            {
                  if(ref[i] == temp[j])
                  {
                        s++;
                        f--;
                  }
            }     
            f++;
            if((f <= frames) && (s == 0))
            {
                  temp[i] = ref[i];
            }   
            else if(s == 0)
            {
                  temp[(f - 1) % frames] = ref[i];
            }
            printf("\n");
            for(int j = 0; j < frames; j++)
            {     
                  printf("%d\t", temp[j]);
            }
      } 
      printf("\nans:%d\n", f);

      return f;
}


int Optimal(int ref[], int f, int p, int frames)
{
      int temp[frames];
      int pos, max;
      for(int i=0; i<frames; i++)
      {
            temp[i] = -1;
      }

      for(int i = 0; i < p; ++i)
      {
            int f1 = 0;
            int f2 = 0;
            for(int j=0; j < frames; ++j)
            {
                  if(temp[j] == ref[i]){
                        f1 = f2 = 1;
                        break;
                  }
            }
            if(f1 == 0)
            {
                  for(int j = 0; j < frames; ++j)
                  {
                        if(temp[j] == -1)
                        {
                              f++;
                              temp[j] = ref[i];
                              f2 = 1;
                              break;
                        }
                  }
            }
            if(f2 == 0)
            {
                  int f3 =0;
                  for(int j = 0; j < frames; ++j)
                  {
                        temp[j] = -1;
                        for(int k = i + 1; k < p; ++k)
                        {
                              if(temp[j] == ref[k])
                              {
                                    temp[j] = k;
                                    break;
                              }
                        }
                  }
                  for(int j = 0; j < frames; ++j){
                        if(temp[j] == -1)
                        {
                              pos = j;
                              f3 = 1;
                              break;
                        }
                  }

                  if(f3 ==0)
                  {
                        max = temp[0];
                        pos = 0;
                        for(int j = 1; j < frames; ++j)
                        { 
                              if(temp[j] > max)
                              {
                                    max = temp[j];
                                    pos = j;
                              }
                        }
                  }
                  temp[pos] = ref[i];
                  f++;
            }

            printf("\n");
            for(int j = 0; j < frames; ++j)
            {
                  printf("%d\t", temp[j]);
            }
      }
      printf("\nans: %d", f);

      return f;
}


int findLRU(int time[], int n)
{
      int min = time[0];
      int pos = 0;
       
      for(int i = 1; i < n; ++i)
      {
            if(time[i] < min)
            {
                  min = time[i];
                  pos = i;
            }
      }
      return pos;
}


int LRU(int ref[], int f, int p, int frames)
{
      int c = 0, flag1, flag2, pos;
      int time[10];
      int temp[frames];
      for(int i=0; i<frames; i++)
      {
            temp[i] = -1;
      }

      for(int i = 0; i < p; ++i)
      {
            flag1 = flag2 = 0;

            for(int j = 0; j < frames; ++j)
            {
                  if(temp[j] == ref[i])
                  {
                        c++;
                        time[j] = c;
                        flag1 = flag2 = 1;
                        break;
                  }
            }
    
            if(flag1 == 0)
            {
                  for(int j = 0; j < frames; ++j)
                  {
                        if(temp[j] == -1)
                        {
                              c++;
                              f++;
                              temp[j] = ref[i];
                              time[j] = c;
                              flag2 = 1;
                              break;
                        }
                  }
            }

            if(flag2 == 0)
            {
                  pos = findLRU(time, frames);
                  c++;
                  f++;
                  temp[pos] = ref[i];
                  time[pos] = c;
            }
          
            printf("\n");
            for(int j = 0; j < frames; ++j)
            {
                  printf("%d\t", temp[j]);
            }
      }
      printf("\nans= %d", f);
          
    return f;
}


int main(void)
{
      int ref[10];
      int f = 0, p, frames;
      printf("No. ref: ");
      scanf("%d", &p);
      printf("values: \n");
      for(int i=0; i<p; i++)
      {
            scanf("%d", &ref[i]);
      }
      printf("frames: ");
      scanf("%d", &frames);

      printf("\nFIFO: \n");
      int fifo = FIFO(ref, f, p, frames);
      
      printf("\nOptimal: \n");
      int optimal = Optimal(ref, f, p, frames);

      printf("\nLRU: \n");
      int lru = LRU(ref, f, p, frames);      

      printf("\n\n%s\t%s\t%s\n", "FIFO", "Optimal", "LRU");
      printf("%d\t%d\t%d\n", fifo, optimal, lru);

      printf("\n");

      return 0;
}