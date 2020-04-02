/*
 Memory Allocation
 Static Memory : it is made on program start. and it's size can't be changed.
 Stack Memory : PUSH and POP memory value(the storage of local variable), memory size is 1MB(C6262 Error MAX : 16384).

 Dynamic Memory Allocation(Heap) : Use <malloc.h> , it can be use big size memory. MAX : 2GB
 void *malloc(size_t size); // origina API
 void *p = malloc(100); // allocation 100 bytes memory on Heap.
 ex>
 short *p = (short *)malloc(100); // 50 short(2bytes) group (100bytes / 2bytes = 50)
 int *p = (int *)malloc(100); //25 int(4bytes) group (100bytes / 4bytes = 25)

 Memory Release !!!!!!!!
 free(p);  //Important!!!! Allocated memory have to release by free();

*/

#include <stdio.h>
#include <malloc.h>

void main() {
    /*
    char c[1024][1024];
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            c[i][j] = i * j;
        }
    }
    */// !!!! error C6262(Stack overflow) occurred !!!!//

    char* p_name;
    p_name = (char*)malloc(32);
    if (p_name != NULL) {
        printf("Your name : ");
        gets(p_name);
        printf("Hi~ %s\n", p_name);
        free(p_name);
    }
    else {
        printf("Memory Allocation Error!!");
    }

    int* p1 = (int*)malloc(12);
    int* p2 = (int*)malloc(sizeof(int) * 3);  // same to malloc(12) sizeof(int) is 4bytes 
    short* p2 = (short*)malloc(sizeof(short) * 6);  // same to malloc(12) sizeof(short) is 2bytes 
    
}