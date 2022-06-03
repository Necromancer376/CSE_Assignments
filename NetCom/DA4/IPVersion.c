#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char ipClass = '*';

bool checkIPv4(char* s)
{
	if(strlen(s) == 0)
		return false;
	if(strlen(s) > 1 && s[0] == '0')
		return false;
	if (strlen(s) > 3)
		return false;

	int i = 0;
	for (int j=0; j < strlen(s); j++)
	{
		if (s[j] < '0' || s[j] > '9')
			return false;
	}
	i = atoi(s);

	return i >= 0 && i <= 255;
}

bool checkIPv6(char* s)
{
	if (strlen(s) > 4 || strlen(s) == 0)
		return false;

	for(int i=0; i<strlen(s); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'f')
			continue;
		else if(s[i] >= 'A' && s[i] <= 'F')
			continue;
		else if(s[i] >= '0' && s[i] <= '9')
			continue;
		else
			return false;
	}

	return true;
}

bool IPv4(char* s)
{
	if (s[0] == '.' || s[strlen(s) - 1] == '.')
		return false;

	bool flags[4];
	int count = 0;
	char* ip = (char*)malloc(32*sizeof(char));
	strcpy(ip, s);
	ip = strtok(ip, ".");

	while(ip != NULL)
	{
		if(!checkIPv4(ip))
			return false;

		if(atoi(ip) == 0)
			flags[count] = false;
		else
			flags[count] = true;
		count++;
		ip = strtok(NULL, ".");
	}

	if(flags[0] == 1 && flags[1] == 0 && flags[2] == 0 && flags[3] == 0)
		ipClass = 'A';
	else if(flags[0] == 1 && flags[1] == 1 && flags[2] == 0 && flags[3] == 0)
		ipClass = 'B';
	else if((flags[0] == 1 && flags[1] == 1 && flags[2] == 1 && flags[3] == 0) ||
		(flags[0] == 1 && flags[1] == 0 && flags[2] == 1 && flags[3] == 0))
		ipClass = 'C';
	else
		ipClass = 'D';

	if(count != 4)
		return false;

	return true;
}

bool IPv6(char* s)
{
	if (s[0] == ':' || s[strlen(s) - 1] == ':')
		return false;
	
	int count = 0;
	char* ip = (char*)malloc(32*sizeof(char));
	strcpy(ip, s);
	ip = strtok(ip, ":");

	while(ip != NULL)
	{
		if(checkIPv4(ip))
			return false;
		count++;
		ip = strtok(NULL, ":");
	}

	if(count != 8)
		return false;

	return true;
}

int IdentifyIP(char* ip)
{
	int size = strlen(ip);
	if(size < 7)
		return 0;

	if(IPv4(ip))
	{
		return 1;
	}

	if(size < 15)
		return 0;
	
	if(IPv6(ip))
		return 2;

	return 0;

}


int main(void)
{
	char* ip = (char*)malloc(32*sizeof(char));
	printf("ip: ");
	scanf("%s", ip);

	int temp = IdentifyIP(ip);

	printf("\n");
	switch(temp)
	{
		case 0:
			printf("%s\n", "Neither IPv4 nor IPv6");
			break;
		case 1:
			printf("%s\n", "IPv4");
			break;
		case 2:
			printf("%s\n", "IPv6");
			break;
	}

	printf("class = %c\n", ipClass);
}

// 192.168.0.1
// FE80:CD00:0000:0CDE:1257:0000:211E:729C