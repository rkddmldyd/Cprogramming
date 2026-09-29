// **********************************************
// 제 목 : 10진수 정수를 2진수로 변환하여 출력
// 날 짜 : 2026년 9월 29일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_binary(unsigned int number);

int main(void)
{
    int number;
    unsigned int magnitude;

    printf("10진수 정수 입력: ");
    if (scanf("%d", &number) != 1)
        return 1;

    if (number < 0)
    {
        printf("-");
        magnitude = 0u - (unsigned int)number;
    }
    else
        magnitude = (unsigned int)number;

    print_binary(magnitude);
    printf("\n");

    return 0;
}

void print_binary(unsigned int number)
{
    if (number >= 2)
        print_binary(number / 2);

    printf("%u", number % 2);
}
