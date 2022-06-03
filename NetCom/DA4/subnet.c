#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int checkInput(char arr[])
{
    int netmask;

	if(strspn(arr, "0123456789\n") == strlen(arr))
	{
		netmask = atoi(arr);
		if (netmask >= 0 && netmask <= 32)
		{
			return 1;
		}
	}

	printf("error: 0-32 only\n");
	return 0;
}

long int NumAddr(int mask)
{
	return pow(2, 32 - mask);
}

long int UsableAddr(int mask)
{
	long int hosts;
	hosts = (pow(2, 32 - mask)) - 2;
	if(hosts < 0)
	{
		hosts = 0;
	}
	return hosts;
}

void printAddr(int netmask)
{
	printf("Netmask bits: %d\n\n", netmask);
	printf("Total addresses: %ld\n", NumAddr(netmask));
	printf("Usable addresses: %ld\n", UsableAddr(netmask));
}


int main()
{
	char arr[4] = { 0 };
	int netmask;

	printf("Netmask: ");
	scanf("%2c", arr);

	if(checkInput(arr))
	{
		netmask = atoi(arr);
		printAddr(netmask);
		return 0;
	}
	
	return 0;
}
