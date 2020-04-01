/* Standard Input Output

<stdio.h>
-stdin : standard input
-rewind : delete all buffer of input stream
-getchar : get a character of input (important!! every stream has '\n' end of it, so next getchar() returns '\n')
-rewind(stdin) : remove all values of input buffer
-getc(stdin) : same to getchar()
-gets : get a String of input (it made of getchar function)

<string.h>
-strlen(char[]) : get a length of char-array (String)
<stdlib.h>
-atoi(char[]) : char array(String) to Integer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int user_gets(char buffer[], int limit);
int stringtoint(char buffer[]);

void main() {
	int input_data;
	input_data = getchar();
	rewind(stdin); //getchar();
	printf("first input caracter is %c\n", input_data);
	input_data = getchar();
	rewind(stdin); //getchar();
	printf("second input caracter is %c\n", input_data);

	char input_string[10];
	int getstatus = user_gets(input_string, 9); //gets(input_string);
	if (getstatus == 1) printf("input : %s \n", input_string);
	else printf("input out of range");

	int convertednum = stringtoint("123456");
	printf("input value : %d \n", convertednum);

	int firstnum = 0;
	int secondnum = 0;
	scanf_s("%d %d", &firstnum, &secondnum);
	printf("%d + %d = %d", firstnum, secondnum, firstnum + secondnum);

}

int user_gets(char buffer[], int limit) {
	int i = 0;
	for (i = 0; i < limit; i++) {
		buffer[i] = getchar();
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			return 1;
		}
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0;
}

int stringtoint(char buffer[]) {
	int size = 0;
	int result = 0; 
	/*
	while (buffer[size] != 0) {
		size++;
	}
	*/
	size = strlen(buffer);
	printf("string length is : %d\n", size);
	for (int i = 0 ; i < size ; i++) {
		if ('0' < buffer[i] && '9' > buffer[i]) {
			//result += (buffer[i] - '0') * pow(10, size - i - 1);
			result = result * 10 + (buffer[i] -'0');
		}
	}
	return result;
}

int pow(int num, int sq) {
	int result = 1;
	if (sq == 0) {
		return result;
	}
	for (int i = 0; i < sq; i++) {
		result *= num;
	}
	return result;
}