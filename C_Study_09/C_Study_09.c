/*
	#File input / output

	# compare binary and char
	1. Memory size
		sizeof(var); // size of a data type (bytes)
		strlen(var); // length of a string data 
	2. Memory copy
		char src[8] = {'a','b','c',0,};
		char des[8];
		memcpy(des, src, sizeof(src));
		strcpy(des, src);

	# File Struct
		FILE *p_file;  //define file
		fopen(filename, mode);// FILE *fopen(const char *filename, const char *mode); mode(write , read, binary....)
		fseek(pfile, 0, SEEK_SET); //move position from SEEK_SET(start point) to 0 steps

	# FILE Handling Function
	fopen() : open file
	mode : rwtb+ combination read write text binary +(advantage)
	fclose() : close file
	fscanf() : read a char
	fgets() : read a line (char[])
	fwrite() : write binary data to the file
	fread() : read binary data from the file
	fseek() : move the position in the file
		- SEEK_SET : start position of the file
		- SEEK_END : end position of the file
		- SEEK_CUR : current position of the file
	ftell() : check the current position from start position of the file
*/
#include <stdio.h>

void read_aline1();
void read_All();
void read_aline2();
void write_aline1();
void write_datas();
void read_datas();
void check_filesize();

int main(int argc, char* args[]) {
	//read_aline1();
	//read_All();
	//read_aline2();
	//write_aline1();
	write_datas();
	read_datas();
	check_filesize();
}

void read_aline1() {
	int num1, num2, num3;
	FILE* p_file;
	fopen_s(&p_file, "test.txt", "rt");

	if (NULL != p_file) {
		fscanf_s(p_file, "%d %d %d", &num1, &num2, &num3);
		printf("%d %d %d", num1, num2, num3);
		fclose(p_file);
	}
	else {
		// if there is no file and open faulty.
	}
}

void read_All() {
	int num1;
	FILE* p_file;
	fopen_s(&p_file, "test.txt", "rt");

	if (NULL != p_file) {
		while (EOF != fscanf_s(p_file, "%d", &num1)) {
			printf("%d\n", num1);
		}
		fclose(p_file);
	}
	else {
		// if there is no file and open faulty.
	}
}

void read_aline2() {
	char temp[64];
	FILE* p_file;
	fopen_s(&p_file, "test.txt", "rt");
	if (NULL != p_file) {
		while (NULL != fgets(temp, sizeof(temp), p_file)) {
			printf("%s", temp);
		}
		fclose(p_file);
	}
}

void write_aline1() {
	int data = 0x00000412;
	FILE* p_file;
	fopen_s(&p_file, "test.dat", "wb");
	if (NULL != p_file) {
		fwrite(&data, sizeof(int), 1, p_file);
	}
	fclose(p_file);
}

void write_datas() {
	int data = 100, data_list[5] = { 0,1,2,3,4 };
	FILE* p_file;
	fopen_s(&p_file, "test.dat", "wb");
	if (NULL != p_file) {
		fwrite(&data, sizeof(int), 1, p_file);
		fwrite(&data_list, sizeof(int), 5, p_file);
	}
	fclose(p_file);
}

void read_datas() {
	int data = 0, data_list[5] = { 9,9,9,9,9 };
	FILE* p_file;
	fopen_s(&p_file, "test.dat", "rb");
	if (NULL != p_file) {
		fread(&data, sizeof(int), 1, p_file);
		fread(&data_list, sizeof(int), 5, p_file);
		printf("%d\n", data);
		for (int i = 0; i < 5; i++) {
			printf("%d%\n", data_list[i]);
		}
	}
	fclose(p_file);
}

void check_filesize() {
	int file_size = 0;
	FILE* p_file;
	fopen_s(&p_file, "test.dat", "rb");
	fseek(p_file, 0, SEEK_END);
	file_size = ftell(p_file);
	printf("File size : %dbytes \n", file_size);
	fclose(p_file);
}