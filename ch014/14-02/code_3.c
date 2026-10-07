// **********************************************
// 제 목 : 포인터 매개변수로 실수의 정수부와 소수부 구하기
// 날 짜 : 2026년 9월 29일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <math.h>

void split_number(double number, int* integer_part, double* fractional_part);

int main(void)
{
    double number, fractional_part;
    int integer_part;

    printf("실수를 입력하시오 : ");
    if (scanf("%lf", &number) != 1)
        return 1;

    if (!isfinite(number) || number < INT_MIN || number > INT_MAX)
    {
        printf("int 범위 안의 유한한 실수를 입력하시오.\n");
        return 1;
    }

    split_number(number, &integer_part, &fractional_part);
    printf("정수부 : %d\n", integer_part);
    printf("소수부 : %.5f\n", fractional_part);

    return 0;
}

void split_number(double number, int* integer_part, double* fractional_part)
{
    *integer_part = (int)number;
    *fractional_part = number - *integer_part;
}
