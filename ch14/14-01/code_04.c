// **********************************************
// 제 목 : 값 전달과 주소 전달을 이용한 정수 100배 비교
// 날 짜 : 2026년 9월 21일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void multiply_value(int value);
void multiply_address(int* value);

int main(void)
{
    int num;

    printf("정수를 입력 하시오: ");
    if (scanf("%d", &num) != 1)
        return 1;

    multiply_value(num);
    printf("값에 의한 호출 후 num: %d\n", num);

    multiply_address(&num);
    printf("주소에 의한 호출 후 num: %d\n", num);

    return 0;
}

void multiply_value(int value)
{
    value *= 100;
}

void multiply_address(int* value)
{
    *value *= 100;
}
