/*
Multi Pointer
**P -> *p -> data
2      1     0
**p -> &data -> data
2      0        0
*/

#include <stdio.h>
#include <malloc.h>

void multipointer2();
void multipointer3();

void main() {
	char** p1;
	char* p2;
	char p3 = 'a';
	p1 = &p2;
	p2 = &p3;
	printf("**P is : %c\n", **p1);
	**p1 = 'c';
	printf("P3 is : %c\n", p3);
	//multipointer2();
	multipointer3();
}

void multipointer2() {
	unsigned char limit[3], *p[3];
	int age, member, temp, sum;

	for (age = 0; age < 3; age++) {
		printf("%d0대의 연령의 윗몸 일으키기 횟수\n", age + 2);
		printf("이 인령대의 인원은 몇명입니까? : ");
		scanf_s("%d", &temp);
		limit[age] =(unsigned char)temp;
		p[age] = (unsigned char*)malloc(limit[age]);
		if (p[age]) {
			for (member = 0; member < limit[age]; member++) {
				printf("%d 번째 : ", member + 1);
				scanf_s("%d", &temp);
				*(p[age] + member) =(unsigned char)temp;
			}
		}
	}

	printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
	for (age = 0; age < 3; age++) {
		sum = 0;
		printf("%d0대 : ", age + 2);
		for (member = 0; member < limit[age]; member++) {
			sum += *(p[age] + member);
		}
		printf("%5.2f \n", (double)sum / limit[age]);
		free(p[age]);
	}

}

void multipointer3() {
	//age member count/each
	unsigned char *age_table,*limit_table, ** p;
	int age, age_step, temp, sum, member;
	printf("연령층이 몇가지 있습니까? : ");
	scanf_s("%d", &age_step);
	limit_table = (unsigned char*)malloc(sizeof(unsigned char)*age_step);
	age_table = (unsigned char*)malloc(sizeof(unsigned char)*age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*)*age_step);

	for (age = 0; age < age_step; age++) {
		printf("%d번째 연령대는? : ", age+1);
		scanf_s("%d", &temp);
		*(age_table + age) = (unsigned char)temp;
		printf("%d번째 연령대인 %d대의 인원수는? : ", age + 1, *(age_table + age));
		scanf_s("%d", &temp);
		*(limit_table + age) = (unsigned char)temp;
		*(p+age) = (unsigned char*)malloc(*(limit_table + age));
		for (member = 0; member < *(limit_table + age); member++) {
			printf("%d 대 %d 번째 인원의 윗몸일으키기 횟수 : ", *(age_table+age), member +1);
			scanf_s("%d", &temp);
			*(*(p + age) + member) = temp;
		} 
	}
	
	for (age = 0; age < age_step; age++){
		sum = 0;
		printf("%d번째 연령대인 %d대의 평균 윗몸일으키기 횟수는 : ", age + 1, *(age_table + age));
		for (member = 0; member < *(limit_table + age); member++) {
			sum += *(*(p + age) + member);
		}
		printf("%5.2f\n", (double)sum / *(limit_table + age));
		free(*(p + age));
	}
	free(p);
	free(limit_table);
	free(age_table);
}