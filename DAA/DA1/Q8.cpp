#include<iostream>
#include<math.h>

using namespace std;


int FibRec(int n)
{
	if(n <= 1)
		return n;

	return FibRec(n-1) + FibRec(n-2);
}


int FibItr(int n)
{
	int a=0;
	int b=1;

	for(int i=0; i<n; i++)
	{
		int temp = a+b;
		a = b;
		b = temp;
	}

	return a;
}


int FibBinet(int n)
{
	return (1 / sqrt(5))*((pow(((1 + sqrt(5)) / 2), n))- pow(((1 - sqrt(5)) / 2), n));
}


int FibMatrix(int n)
{
	int i=0;
	int mat[2][2] = {{1, 1}, {1, 0}};
	int tempMat[2][2] = {{1, 1}, {1, 0}};
	int newMat[2][2];

	for(int i=0; i<n-1; i++)
	{
		newMat[0][0] = (mat[0][0] * tempMat[0][0]) + (mat[0][1] * tempMat[1][0]);
		newMat[0][1] = (mat[0][0] * tempMat[0][1]) + (mat[0][1] * tempMat[1][1]);
		newMat[1][0] = (mat[1][0] * tempMat[0][0]) + (mat[1][1] * tempMat[1][0]);
		newMat[1][1] = (mat[1][0] * tempMat[0][1]) + (mat[1][1] * tempMat[1][1]);

		for (int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				tempMat[i][j] = newMat[i][j];
	}

	return tempMat[0][1];
}


int main()
{
	int n;
	cout << "n: ";
	cin >> n;

	cout << "Recursive: " << FibRec(n) << endl;
	cout << "Iterative: " << FibItr(n) << endl;
	cout << "Binet: " << FibBinet(n) << endl;
	cout << "Matrix: " << FibMatrix(n) << endl;
}