/*
	#User defined Type
		typedef unsigned char US; // US type is created.
		US number;   // created a number variable using US instead of unsigned char type.
	#User defined Struct
		struct People{
			char name[12];
		}
	#Combine User define type with struct
		typedef struct People{
			char name[12];
		}Person;
*/
#include <stdio.h>
#include <malloc.h>

typedef struct People{
	char name[12];
	unsigned short int age;
	float height;
	float weight;
}Person;

void print_person();
void print_persons();
void add_friend(Person(*friends)[]);
void show_friends(Person(*friends)[]);
void manage_friends();

void main() {
	//print_person();
	//print_persons();
	manage_friends();
}

void print_person() {
	Person person;

	printf("이름을 입력하세요 : ");
	scanf_s("%s", person.name, sizeof(person.name));
	printf("나이를 입력하세요 : ");
	scanf_s("%hu", &person.age);
	printf("키를 입력하세요 : ");
	scanf_s("%f", &person.height);
	printf("몸무게를 입력하세요 : ");
	scanf_s("%f", &person.weight);

	printf("\n%s의 정보\n", person.name);
	printf("나이 : %d\n", person.age);
	printf("키 : %.1f\n", person.height);
	printf("몸무게 : %.1f\n", person.weight);
}

void print_persons() {
	int members;
	printf("인원수를 입력하세요 : ");
	scanf_s("%d", &members);
	Person* person = (Person*)malloc(sizeof(Person) * members);
	for (int i = 0; i < members; i++) {
		printf("이름을 입력하세요 : ");
		//scanf_s("%s", (*(person+i)).name, sizeof((*(person+i)).name));
		scanf_s("%s", (person+i)->name, sizeof((person+i)->name));
		printf("나이를 입력하세요 : ");
		//scanf_s("%hu", &(*(person + i)).age);
		scanf_s("%hu", &((person + i)->age));
		printf("키를 입력하세요 : ");
		//scanf_s("%f", &(*(person + i)).height);
		scanf_s("%f", &((person + i)->height));
		printf("몸무게를 입력하세요 : ");
		//scanf_s("%f", &(*(person + i)).weight);
		scanf_s("%f", &((person + i)->weight));
	}

	for (int i = 0; i < members; i++) {
		printf("\n%s의 정보\n", (person + i)->name);
		printf("나이 : %d\n", (person + i)->age);
		printf("키 : %.1f\n", (person + i)->height);
		printf("몸무게 : %.1f\n", (person + i)->weight);
	}
}

void manage_friends() {
	Person (*friends)[5];
	int count = 0;
	unsigned short int service = 0;
	while (service != 3) {
		printf("======[Menu]======\n");
		printf("1. Add Friend\n");
		printf("2. Show Friend List\n");
		printf("3. Exit\n");
		printf("==================\n");
		printf("Choice Number : ");
		scanf_s("%hu", &service);
		switch (service) {
		case 1 :
			add_friend(&friends);
			break;
		case 2 : 
			show_friends(&friends);
			break;
		case 3 :
			break;
		default :
			printf("Enter Correct Number!!\n");
			break;
		}
	}
}

void add_friend(Person (*friends)[]) {
	int count;
	for (count = 0; count < 5; count++) {
	printf("친구를 추가하십시요");
	printf("친구의 이름 : ");
	scanf_s("%s", ((*friends)[count].name), sizeof((*friends)[count].name));
	printf("친구의 나이 : ");
	scanf_s("%hu", &((*friends)[count].age));
	printf("친구의 키 : ");
	scanf_s("%f", &((*friends)[count].height));
	printf("친구의 몸무게 : ");
	scanf_s("%f", &((*friends)[count].weight));
	}
}

void show_friends(Person (*friends)[]) {
	int count;
	for (count = 0; count < 5; count++) {
		printf("%s 친구의 정보", ((*friends)[count].name));
		printf("나이 : %d ", (*friends)[count].age);
		printf("키 : %.1f ", (*friends)[count].height);
		printf("몸무게 : %.1f", (*friends)[count].weight);
	}
}

