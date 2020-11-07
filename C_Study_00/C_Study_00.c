#include <stdio.h>

void star();

void main(void) {
	int num = 0;
	printf("단수를 입력하세요\n");
	scanf_s("%d", &num);
	for (int i = 1; i <= 9; i++) {
		printf("%d * %d = %d \n", num, i, num * i);
	}
	star();
}

void star(void) {
	int count = 9;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
		{
			if (count <= j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		count--;
	}
}
