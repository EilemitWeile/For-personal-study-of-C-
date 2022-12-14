#define _CRT_SECURE_NO_WARNINGS
//#define MAX_COUNT 2 // 입력 받는 인원 수
#include<stdio.h>
#include<string.h>
//#include<stdlib.h>

//목록보기로 이름, 전화번호, 주소, 생일 및 저장되어있는 모든 값 출력
//추가하기로 값을 입력받기
//탐색하기로 특정 값을 찾고, 찾은 값 출력
//삭제하기로 찾은 값을 지우기, 메모리 반환

typedef struct person
{
    char name[20];   //배열은 1차원으로!
    char number[15];
    char address[50];
    char birth[10];

} personType;



typedef int menuType;

personType Person[2];
int people = 0; // 몇명 저장되어 있는지 확인
char choice[4][50] = { "이름", "전화번호", "주소", "생일" };
char Menu[4][50] = { "1. 목록보기", "2. 추가하기", "3. 탐색하기", "4. 삭제하기" };



void showmenu() {                  //저장되어있는 모든 값 출력

    int i;
    printf("%20s %15s %50s %10s\n", choice[0], choice[1], choice[2], choice[3]);
    for (i = 0; i < people; i++) {
        printf_s("%20s %15s %50s %10s\n", Person[i].name, Person[i].number, Person[i].address, Person[i].birth);   //구조체에 저장된 모든 값 출력

    }
    printf_s("\n");
}


void information() {             //값을 입력받아 제 위치에 저장, 출력은 목록보기에서


    if (people == 2)
    {
        printf_s("=> 추가하기 불가\n");
        return;
    }


    int i = 0; //, j;

    for (i = 0; i < 2; i++) {                     // for문으로 값 입력 설계
        printf_s("\n 이름 %d : ", i + 1);
        scanf_s("%[^\n]s", Person[i].name, 20); // 이름 입력
        getchar();                                   // 인덱스 people 아니라 i로

    }


    for (i = 0; i < 2; i++) {
        printf_s("\n 전화번호 %d : ", i + 1);
        scanf_s("%[^\n]", Person[i].number, 15); // 번호 입력
        getchar();

    }


    for (i = 0; i < 2; i++) {
        printf_s("\n 주소 %d : ", i + 1);
        scanf_s("%[^\n]", Person[i].address, 50); // 주소 입력
        getchar();

    }


    for (i = 0; i < 2; i++) {
        printf_s("\n 생일 %d : ", i + 1);
        scanf_s("%[^\n]", Person[i].birth, 10); // 생일 입력
        getchar();


    }
    people += 2; //인원 증가 필요!, 2명 입력 받으므로 인원 2명 증가!

}


void search() {        //탐색하기, 이름을 입력받아 값이 존재하는지 여부 확인

    int i;
    char name[20];
    printf_s("검색할 이름 : ");
    scanf_s("%[^\n]", name, 20);
    getchar();

    for (i = 0; i < people; i++) {                        //검색된 이름을 구조체 name에서 존재 여부 확인

        if (strcmp(name, Person[i].name) == 0) {  // 같은 이름이 존재한다면


            printf_s("%20s %15s %50s %10s\n", Person[i].name, Person[i].number, Person[i].address, Person[i].birth);


            return;
        }
    }
    printf_s("=> 없음\n");



}


void deletedata() {        //삭제하기, 이름을 입력받아 해당 관련 데이터 전부 삭제




    int i, j;
    char name[20];
    printf_s("삭제할 이름 : ");
    scanf_s("%[^\n]", name, 20);
    getchar();

    for (i = 0; i < people; i++)
    {
        if (strcmp(name, Person[i].name) == 0)
        {
            strcpy(Person[i].name, "");
            strcpy(Person[i].number, "");
            strcpy(Person[i].address, "");
            strcpy(Person[i].birth, "");

            for (j = i; j < people - 1; j++)
            {
                strcpy(Person[j].name, Person[j + 1].name);
                strcpy(Person[j].number, Person[j + 1].number);
                strcpy(Person[j].address, Person[j + 1].address);
                strcpy(Person[j].birth, Person[j + 1].birth);
                people--;
            }
            printf("[%s] 정보 삭제됨\n", name);
            return;
        }
        printf("=> 없음\n");
    }





}




int main() {

    menuType selection;


    while (1)
    {

        printf_s("1. 목록보기, 2. 추가하기, 3. 탐색하기, 4. 삭제하기 \n");
        scanf_s("%d", &selection);
        getchar();

        switch (selection)
        {
        case 1: // 목록보기
            showmenu();
            break;
        case 2: // 추가하기
            information();
            break;
        case 3: // 검색하기
            search();
            break;
        case 4: // 삭제하기
            deletedata();
            break;
        case 0: // 종료
            return 0;
        }
    }
    return 0;

}