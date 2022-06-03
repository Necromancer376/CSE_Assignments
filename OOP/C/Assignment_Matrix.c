#include<stdio.h>
#include<stdlib.h>


void PrintMat(int row, int col, int mat[row][col])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


int Addition(int m, int n, int p, int q, int A[m][n], int B[p][q], int answer[m][n])
{
    int i, j;

    if(m == p && n == q)
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                answer[i][j] = A[i][j] + B[i][j];
            }
        }

        return 1;
    }

    return 0;
}


int Subtraction(int m, int n, int p, int q, int A[m][n], int B[p][q], int answer[m][n])
{
    int i, j;

    if(m == p && n == q)
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                answer[i][j] = A[i][j] - B[i][j];
            }
        }

        return 1;
    }

    return 0;
}


int Multiply(int m, int n, int p, int q, int A[m][n], int B[p][q], int answer[n][q])
{
    int i, j, k;

    if(n != p)
        return 0;

    for(i =0; i < m; i++)
    {
        for(j=0; j < q; j++)
        {
            int temp = 0;
            for(k=0; k < n; k++)
            {
                temp = temp + (A[i][k] * B[k][j]);
            }
            answer[i][j] = temp;
        }
    }

    return 1;
}


int IsSparse(int m, int n, int mat[m][n])
{
    int i, j;
    int zero = 0;
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j] == 0)
                zero++;
            if(zero > m*n - zero)
                return 1;
        }
    }

    return 0;
}


int main()
{
    int input, check, row1, row2, col1, col2;

    printf("1. Check Sparce\n2. Multiply\n3. Addition\n4. Subtraction\n\nInput: ");
    scanf("%d", &input);
    printf("_______________________________\n");

    if(input == 1)
    {
        printf("row, column: ");
        scanf("%d %d", &row1, &col1);

        int A[row1][col1];

        printf("Elements of A: \n");

        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<col1; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }
        printf("\n");

        check = IsSparse(row1, col1, A);
        if(check == 0)
            printf("Matrix is not sparse\n");
        else
            printf("Matrix is Sparse\n");
    }

    else
    {
        printf("row, column: ");
        scanf("%d %d", &row1, &col1);

        int A[row1][col1];

        printf("Elements of A: \n");

        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<col1; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }

        printf("row, column: ");
        scanf("%d %d", &row2, &col2);

        int B[row2][col2];

        printf("Elements of B: \n");

        for(int i=0; i<row2; i++)
        {
            for(int j=0; j<col2; j++)
            {
                scanf("%d", &B[i][j]);
            }
        }
        printf("\n");

        int subtract[row1][col1];
        int add[row1][col2];
        int mul[col1][row2];

        switch(input)
        {
            case 2:

                check = Multiply(row1, col1, row2, col2, A, B, mul);
                if(check == 0)
                    printf("Multiplication not possible\n");
                else
                {
                    printf("Multiplication (AB) = \n");
                    PrintMat(row1, col2, mul);
                }
                break;

            case 3:
                check = Addition(row1, col1, row2, col2, A, B, add);

                if(check == 0)
                    printf("Addition not possible\n");
                else
                {
                    printf("Addition (A + B) = \n");
                    PrintMat(row1, col1, add);
                }
                break;

            case 4:
                check = Subtraction(row1, col1, row2, col2, A, B, subtract);

                if(check == 0)
                    printf("Subtraction not possible\n");
                else
                {
                    printf("Subtraction (A - B) = \n");
                    PrintMat(row1, col1, subtract);
                }
                break;

            default:
                printf("Invalid input\n");
                break;

        }
    }

    printf("\n");
}