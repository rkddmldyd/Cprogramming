// **********************************************
// 제 목 : 간접참조를 이용해 출력하기
// 날 짜 : 2026년 9월 8일
// 작성자 : 2600172 정준석
// **********************************************

#include <stdio.h>

int main(void)
{
    int a = -100;
    char b = 'A';
    double c = 3.14;

    int* pa = &a;
    char* pb = &b;
    double* pc = &c;

    printf("int형 변수 a의 값은: %d\n", *pa);
    printf("char형 변수 b의 값은: %c\n", *pb);
    printf("double형 변수 c의 값은: %lf\n", *pc);

    return 0;
}
