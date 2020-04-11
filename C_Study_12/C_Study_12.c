/*
	Separating programming.
	Absolute Path : c:\temp\a\a.c
	Relative Path : a\a.c or ..\b\b.c
*/
#include <stdio.h>
#include "my.h"

extern int num1;
extern int num2;

void main(int agrc, char* args[]) {
	num1 = 80;
	num2 = 1000;
	int num3 = 50;
	int num4 = 60;
	Output();
	printf("Sum = %d", Sum(num3, num4));
	printf("\nEnd");
}

