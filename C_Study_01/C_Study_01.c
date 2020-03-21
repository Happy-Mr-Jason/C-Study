#include <stdio.h>
// Shift Operator 

void upper_case(char* c);

void main(void) {
	int num1 = 0x8000; //1000 0000 0000 0000
	int num2 = 0x0001; //0000 0000 0000 0001
	for (int i = 0; i < 16; i++) {
		printf("num1 >> %d : %4.4x\n", i, num1 >> i );
		printf("num2 << %d : %4.4x\n", i, num2 << i);
	}
	char mchar[] = "hello world";
	upper_case(mchar);
	printf(mchar);
}

void upper_case(char c[]) {
	int index = 0;
	while(c[index]){
		//printf(c[index]);
		if ('a' < c[index] && 'z' > c[index]) {
			c[index] = c[index] - 'a' + 'A';
		}
		index++;
	}
}
