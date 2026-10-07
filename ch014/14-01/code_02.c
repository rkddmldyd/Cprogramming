// **********************************************
// 제 목 : 반환값을 이용하여 정수에 2 더하기
// 날 짜 : 2026년 9월 21일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add2(int value);

int main(void)
{
    int number;

    printf("정수를 입력 하시오: ");
    if (scanf("%d", &number) != 1)
        return 1;

    number = add2(number);
    printf("2만큼 증가한 값: %d\n", number);

    return 0;
}

int add2(int value)
{
    return value + 2;
}
