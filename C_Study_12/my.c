#include <stdio.h>
#include "my.h"

int num1 = 20;
int num2 = 100;

void Output() {
	printf("%d + %d = %d\n", num1, num2, Sum(num1, num2));
}

int Sum(int a, int b) {
	return a + b;
}