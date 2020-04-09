/*
	#Union Struct
	
	#Compare define and typedef
		#define : Preprocessor  !!Constant!!
		#typedef : user define Type 
	
	//don't use semi-colon(;) at the end of the line
	//make PSI
	#define PSI unsigned short int*  
	PSI p_temp, p1;
	>>>> unsigned short *p_temp, p1;  //ERROR!!!

	//make PSI
	typedef unsigned short int* PSI;
	PSI p_temp, p1;
	>>>> unsigned short *p_temp, *p1;

	#ENUM
	enum MY_COLOR{ BLACK, WHITE, RED, GREEN, BLUE, YELLOW};
			      /BLACK = 0 ................. YELLOW = 5
	int my_data = GREEN;

	#TEST Code

		#define MY_DEBUG

		#ifdef MY_DEBUG
		... // MY_DEBUG is defined
		#endif
		
		#ifndef MY_DEBUG
		... // MY_DEBUG is not defined
		#endif

		#ifndef _TEST_H_
		#define _TEST_H_
		.... // execute non duplicatable
		#endif

*/

#include <stdio.h>

//#define MY_DEBUG

//union has 4byte size
typedef union ConvertData {
	char c_data; //1bytes
	short int s_data; //2bytes
	int i_data; //4bytes
}CD;

//4byte union type
typedef union SharedType {
	int i_data;
	float f_data;
};

struct MyData {
	char type;
	union SharedType data;
};

struct BitType {
	unsigned char bit_0 : 1;   //1bit of bit_0
	unsigned char bit_1 : 1;
	unsigned char bit_2 : 1;
	unsigned char bit_3 : 1;
	unsigned char bit_4 : 1;
	unsigned char bit_5 : 1;
	unsigned char bit_6 : 1;
	unsigned char bit_7 : 1;
};

union BitData {
	struct BitType bit_data;
	unsigned char byte_data;
};

enum MY_COLOR { BLACK, WHITE, RED, GREEN, BLUE, YELLOW };

int main(int argc, char* args[]) {
	CD temp;
	temp.i_data = 0x12345678;
	printf("%x\n", temp.c_data);
	printf("%x\n", temp.s_data);
	printf("%x\n", temp.i_data);

	struct MyData a, b;
	a.type = 0;
	a.data.i_data = 100;
	b.type = 1;
	b.data.f_data = 3.14f;

	struct BitType data;
	// data = 0b111100101
	data.bit_0 = 1;
	data.bit_1 = 0;
	data.bit_2 = 1;
	data.bit_3 = 0;
	data.bit_4 = 0;
	data.bit_5 = 1;
	data.bit_6 = 1;
	data.bit_7 = 1;
	unsigned char temp1;
	//temp1 = data; //ERROR!!!!
	//temp1 = (unsigned char)data; //ERROR!!!!
	//memcpy(&temp1, &data, 1); // No ERROR... but.. wrong

	union BitData temp2;
	temp2.byte_data = 0x63;
	temp2.bit_data.bit_0 = 0;
	temp1 = temp2.byte_data;
	printf("%x", temp1);

	int my_color = GREEN;
}

int ProcessData(int data) {
	int result;
#ifdef MY_DEBUG
	if (data < 250)
#endif
		result = data * 100;
#ifdef MY_DEBUG
	else
		printf("Error!!\n");
#endif
	return result;
}
