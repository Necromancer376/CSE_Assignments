#include <stdio.h>
#include <stdlib.h>
 
void main()
{
    int data[10];
    int atrec[10],c,c1,c2,c3;

    printf("4 bit data:  ");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);

    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];
     
    printf("\nEncoded data:  ");
    for(int i=0;i <7; i++)
        printf("%d", data[i]);

    printf("\n\nreceived data:  ");
    for(int i=0; i<7; i++)
        scanf("%d", &atrec[i]);
     
    c1 = atrec[6] ^ atrec[4] ^ atrec[2] ^ atrec[0];
    c2 = atrec[5] ^ atrec[4] ^ atrec[1] ^ atrec[0];
    c3 = atrec[3] ^ atrec[2] ^ atrec[1] ^ atrec[0];
    c = c3 * 4 + c2 * 2 + c1 ;
    
    if(c == 0)
    {
        printf("\nNo error\n");
    }
    else
    {
        printf("\nError on position %d", c);

        printf("\nSent : ");
        for(int i=0; i<7; i++)
            printf("%d", data[i]);
                
        printf("\nReceived: ");
        for(int i=0; i<7; i++)
            printf("%d", atrec[i]);
        printf("\nCorrect: ");
        
        if(atrec[7-c] == 0)
            atrec[7-c] = 1;
        else
            atrec[7-c] = 0;
        for (int i=0; i<7; i++)
            printf("%d", atrec[i]);
    }
    printf("\n");
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>


// char *strrev(char *str)
// {
//     char *p1, *p2;

//     if (! str || ! *str)
//         return str;
//     for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
//     {
//         *p1 ^= *p2;
//         *p2 ^= *p1;
//         *p1 ^= *p2;
//     }
//     return str;
// }

// char* Hamming(char *code, int pos, int n)
// {
//  int c = 0, i;
//  i = pos - 1;

//  while(i < n)
//  {
//      for(int j = i; j< i+ pos; j++)
//      {
//          if(*(code + j) == '1')
//              c++;

//      }
//      i += 2 * pos;
//  }

//  if(c %2 == 0)
//      return "0";
//  else
//      return "1";
// }

// void Solve(char *data, char *code)
// {
//  int n, m, r = 0 , temp = 0;
//  int j = 0, k = 0;
//  n = strlen(data);

//  while (n > (int)pow(2, temp) - (temp + 1))
//  {
//         r++;
//         temp++;
//     }
//     m = n + r;

//     for(int i=0; i<m; i++)
//      strcat(code, "0");

//     for(int i=0; i<m; i++)
//     {
//      if(i == ((int)pow(2, k) - 1))
//      {
//          memcpy(code+i, "0", 1);
//          k++;
//      }
//      else
//      {
//          memcpy(code+i, "2", 1);
//          j++;
//      }
//     }

//     for(int i=0; i<r; i++)
//     {
//      int pos = (int)pow(2, i);
//      char* val = Hamming(code, pos, m);
//      memcpy(code + pos-1, val, 1);
//     }

//     // strrev(code);
// }

// int main(void)
// {
//  char *data = (char*)malloc(32*sizeof(char));
//  char *code = (char*)malloc(64*sizeof(char));

//  printf("Data: ");
//  scanf("%s", data);

//  Solve(data, code);

//  printf("\nCode: %s\n", code);
// }
