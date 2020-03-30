#include <stdio.h>

void uppercase(char* str);
void lowercase(char* str);

void main(void) {
	short birthday;  //normal variable
	short* ptr;      //pointer variable
	ptr = &birthday; //get the address of birthday
	char str[] = "hello WORLD";

	printf("birthday 변수의 주소는 %p 입니다.\n", ptr);
	printf("birthday 변수의 값은 %d 입니다. \n", birthday);
	*ptr = 1042;
	printf("birthday 변수의 값은 %d 입니다. \n", birthday);
	
	printf("Original : %s \n", str);
	uppercase(&str);
	printf("Uppercase : %s\n", str);
	lowercase(&str);
	printf("Lowercase : %s\n", str);
}

void uppercase(char *str) {
	while (*str) {
		if ('a' < *str && 'z' > *str) {
			*str = *str - 'a' + 'A';
		}
		str++;
	}
}

void lowercase(char* str) {
	while (*str) {
		if ('A' < *str && 'Z' > * str) {
			*str = *str - 'A' + 'a';
		}
		str++;
	}
}

