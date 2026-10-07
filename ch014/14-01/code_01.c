// **********************************************
// 제 목 : 주소에 의한 호출로 정수에 2 더하기
// 날 짜 : 2026년 9월 21일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add2(int* value);

int main(void)
{
    int number;

    printf("정수를 입력 하시오: ");
    if (scanf("%d", &number) != 1)
        return 1;

    add2(&number);
    printf("2만큼 증가한 값: %d\n", number);

    return 0;
}

void add2(int* value)
{
    *value += 2;
}
