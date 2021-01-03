//============================================================================
// Name        : CFirstTest.cpp
// Author      : erahkur
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<stdlib.h>

namespace {

const int MAX_LENGTH = 200;

}

void printTemperature() {
	float fahr, celcius;
	int lower = 0, upper = 300, step = 20;

	fahr = lower;

	while (fahr <= upper) {
		celcius = 5 * (fahr - 32) / 9;
		printf("%f-> %f \n", fahr, celcius);
		fahr = fahr + step;
	}

	return;
}

int getLine(char s[], int limit)
{
	int input = 0;
	int index = 0;
    while(index < limit -1 && (input = getchar()) != EOF && input != '\n')
    {
    	s[index++] = input;
    }

    s[index] = '\0'; // null terminate the string
    return index;
}

int copy(char to[], char from[])
{
    // assume to is big enough

	int i = 0;
	while((to[i++] = from[i]) != '\0');

	return i;
}
/*int main() {




}*/

