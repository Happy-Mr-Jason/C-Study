/*
 Pointer with Array
 char *p[5] = *(p[5]) // this array has 5-pointers
 char (*p)[5]  // it has a pointer and a array of 5-char
 */

#include <stdio.h>

void pointandarray();

void main() {
    pointandarray();
}

void pointandarray() {
    char data1, data2, data3, data4, data5;
    char* p1[5] = { &data1, &data2, &data3, &data4, &data5 };
    char(*p2)[5];
    char data10[5];
    *p1[0] = 10;
    *p1[1] = 20;
    *p1[2] = 30;
    *p1[3] = 40;
    *p1[4] = 50;
    printf("%d %d %d %d %d\n", data1, data2, data3, data4, data5);
    p2 = &data10;
    (*p2)[0] = 60;
    (*p2)[1] = 70;
    (*p2)[2] = 80;
    (*p2)[3] = 90;
    (*p2)[4] = 100;
    printf("%d %d %d %d %d\n", (*p2)[0], (*p2)[1], (*p2)[2], (*p2)[3], (*p2)[4]);
    printf("%d %d %d %d %d\n", data10[0], data10[1], data10[2], data10[3], data10[4]);
}