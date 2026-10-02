// **********************************************
// 제 목 : 2차원 배열과 포인터 표현을 이용한 행렬 덧셈
// 날 짜 : 2026년 10월 2일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a[2][2] = { { 2, 4 }, { 5, -5 } };
    int b[2][2] = { { -2, 3 }, { 0, -5 } };
    int result[2][2] = { 0 };
    int i, j;

    // 1. 배열 표현을 이용한 행렬 덧셈과 출력
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            result[i][j] = a[i][j] + b[i][j];

    printf("배열 표현을 이용한 연산결과:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%4d", result[i][j]);
        printf("\n");
    }

    // 2. 포인터 표현을 이용한 행렬 덧셈과 출력
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            *(*(result + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);

    printf("\n포인터 표현을 이용한 연산결과:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%4d", *(*(result + i) + j));
        printf("\n");
    }

    return 0;
}
