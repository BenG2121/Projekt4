// Imports
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "ctype.h"

// Defines
#define stringLength 14
#define partial(a , b) (a/b)*log2(a/b)
// Global Functions
double getShannonEntropy(char*);
void sortStringArray(char*);
void setStringToLowerCase(char*);
// Global Variables
char sRndString[stringLength] = "Hello, world!";
double dShannonEntropy = 0;

unsigned int a0 = 1;
unsigned int a1 = 23;

int main()
{
	setStringToLowerCase(sRndString);
	getShannonEntropy(sRndString);
	sortStringArray(sRndString);
	//printf("%f\n", dShannonEntropy);
	while(1);
	return 0;
}

double getShannonEntropy(char* sRndStr)
{
	unsigned int i = 0;
	double iEntropy = 0.0;
	unsigned int N = stringLength - 1;
	double a, b, c, d, e;
	
	
	for (i = 1; i <= N -1; i++)
	{
		iEntropy = iEntropy + (double)i/ (double)N*log2((double)i/(double)N);
	}
	printf("%f\n", -iEntropy);
	a = 1.0;
	b = 2.0;
	c = 3.0;
	d = 4.0;
	e = 10.0;
	iEntropy = partial(a, e) + partial(b, e) + partial(c, e) + partial(d, e);

	printf("%f\n", -iEntropy);
	
	

	return dShannonEntropy;
}

void sortStringArray(char* UnsortedString)
{
	unsigned int i,n = 0;
	unsigned int uiStringLength = stringLength;
	char tmpChar = {};
	char tmpArray[stringLength] = {};
	memcpy(tmpArray,UnsortedString, stringLength);
	
	

	for (n = uiStringLength-1; n > 1; n--)
	{
		for (i = 1; i < n; i++)
		{
			printf("%s: ", tmpArray);
			printf("%c > %c =  %i \n", tmpArray[i - 1], tmpArray[i], (tmpArray[i - 1] > tmpArray[i]));
			
			if (tmpArray[i - 1] > tmpArray[i])
			{
				printf("%c > %c \n", tmpArray[i - 1], tmpArray[i]);
				tmpChar = tmpArray[i];
				tmpArray[i] = tmpArray[i - 1];
				tmpArray[i - 1] = tmpChar;
			}
		}
	}
}
void setStringToLowerCase(char* RandomCaseString)
{
	unsigned int i = 0;
	for (i = 0; i < stringLength - 1; i++)
	{
		RandomCaseString[i] = tolower(RandomCaseString[i]);
	}
}


