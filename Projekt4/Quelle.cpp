// Imports
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "ctype.h"

// Defines
#define DebugMode 0
#define stringLength1 37
#define stringLength2 37
#define stringLength3 41
#define stringLength4 33
// Global Functions
double getShannonEntropy(char*, unsigned int);
void sortStringArray(char*, unsigned int);
void setStringToLowerCase(char*, unsigned int);
// Global Variables

char sRndString1[stringLength1] = "122333444455555666666777777788888888";
char sRndString2[stringLength2] = "563881467447538846567288767728553786";
char sRndString3[stringLength3] = "https://www.reddit.com/r/dailyprogrammer";
char sRndString4[stringLength4] = "int main(int argc, char *argv[])"; 

double dShannonEntropy = 0;

unsigned int a0 = 1;
unsigned int a1 = 23;

int main()
{
	printf("Shannon-Entropy of %s is", sRndString1);
	setStringToLowerCase(sRndString1, stringLength1);
	sortStringArray(sRndString1, stringLength1);
	dShannonEntropy = getShannonEntropy(sRndString1, stringLength1);
	printf(" = %.9f \n", dShannonEntropy);
	
	printf("Shannon-Entropy of %s is", sRndString2);
	setStringToLowerCase(sRndString2, stringLength2);
	sortStringArray(sRndString2, stringLength2);
	dShannonEntropy = getShannonEntropy(sRndString2, stringLength2);
	printf(" = %.9f \n", dShannonEntropy);

	printf("Shannon-Entropy of %s is", sRndString3);
	setStringToLowerCase(sRndString3, stringLength3);
	sortStringArray(sRndString3, stringLength3);
	dShannonEntropy = getShannonEntropy(sRndString3, stringLength3);
	printf(" = %.9f \n", dShannonEntropy);

	printf("Shannon-Entropy of %s is", sRndString4);
	setStringToLowerCase(sRndString4, stringLength4);
	sortStringArray(sRndString4, stringLength4);
	dShannonEntropy = getShannonEntropy(sRndString4, stringLength4);
	printf(" = %.9f \n", dShannonEntropy);

	while(1);
	return 0;
}

double getShannonEntropy(char* sRndStr, unsigned int stringLength)
{
	unsigned int i = 0;
	double iEntropy = 0.0;
	unsigned int N = stringLength-1;
	double numOfCharacter = 1;
	
	for (i = 0; i < N; i++)
	{
#if(DebugMode == 1)
		printf("%c",sRndStr[i]);
#endif
		if (sRndStr[i] == sRndStr[i+1])
		{
			numOfCharacter++;
		}
		else
		{
			iEntropy = iEntropy + (double)numOfCharacter / (double)N*log2((double)numOfCharacter / (double)N);
#if(DebugMode == 1)
			printf("\n Count: %.1f \n",numOfCharacter);
#endif
			numOfCharacter = 1;
			
		}
	}
	dShannonEntropy = -iEntropy;
#if(DebugMode == 1)
	printf("%f\n", dShannonEntropy);
#endif


	return dShannonEntropy;
}

void sortStringArray(char* UnsortedString , unsigned int stringLength)
{
	unsigned int i,n = 0;
	char tmpChar = {};
	char tmpArray[100] = {};
	memcpy(tmpArray,UnsortedString, stringLength - 1);
	
	

	for (n = stringLength - 1; n > 1; n--)
	{
		for (i = 1; i < n; i++)
		{			
			if (tmpArray[i - 1] > tmpArray[i])
			{
				tmpChar = tmpArray[i];
				tmpArray[i] = tmpArray[i - 1];
				tmpArray[i - 1] = tmpChar;
			}
		}
	}

	memcpy(UnsortedString, tmpArray, stringLength - 1);
}
void setStringToLowerCase(char* RandomCaseString, unsigned int stringLength)
{
	unsigned int i = 0;
	for (i = 0; i < stringLength - 1; i++)
	{
		RandomCaseString[i] = tolower(RandomCaseString[i]);
	}
}


