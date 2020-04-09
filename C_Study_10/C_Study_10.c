/*
	#Function Pointer

	#CallBack Function

*/

#include <stdio.h>

int Sum(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);

typedef int (*FP_OP)(int, int);

int main(int argc, char* args[]) {
	int result = Sum(3, 4);
	int (*p)(int, int);
	int (*fp[])(int, int) = { &Sum, &Sub, &Mul, &Div };
	p = &Sum;
	int result2 = (*p)(3, 5);
	for (int i = 0; i < 4; i++) {
		int result3 = (*fp[i])(8, 2);
		printf("result : %d\n", result3);
	}
	FP_OP fp2[4] = { &Sum, &Sub, &Mul, &Div };
	char op_table[4] = { '+', '-', '*', '/' };
	for (int i = 0; i < 4; i++) {
		int result4 = fp2[i](10, 2);
		printf("result : %d %c %d = %d\n", 10, op_table[i], 2, result4);
	}
}

int Sum(int a, int b) {
	int result = 0;
	result = a + b;
	return result;
}

int Sub(int a, int b) {
	int result = 0;
	result = a - b;
	return result;
}

int Mul(int a, int b) {
	int result = 0;
	result = a * b;
	return result;
}

int Div(int a, int b) {
	int result = 0;
	result = a / b;
	return result;
}
