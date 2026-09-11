// **********************************************
// 제 목 : 포인터를 증가시키며 실수 입력과 값 변경
// 날 짜 : 2026년 9월 11일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double a[5];
    double* p = a;
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d번째 실수 입력: ", i + 1);
        if (scanf("%lf", p++) != 1)
            return 1;
    }

    p = a;
    for (i = 0; i < 5; i++)
    {
        *p += 2.0;
        p++;
    }

    p = a;
    printf("각 원소에 2를 더한 값:");
    for (i = 0; i < 5; i++)
        printf(" %.2f", *p++);
    printf("\n");

    return 0;
}
