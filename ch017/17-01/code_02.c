// **********************************************
// 제 목 : 포인터 배열을 이용하여 최댓값을 구하는 프로그램
// 날 짜 : 2026년 10월 7일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수선언
int get_max(int** ptrarr, int count);

int main(void)
{
    int num1 = 50, num2 = 20, num3 = 30;
    int* ptrarr[3] = { &num1, &num2, &num3 };
    int max;

    max = get_max(ptrarr, 3); // 함수호출
    printf("최댓값:%d\n", max);

    return 0;
}

// 함수정의
int get_max(int** ptrarr, int count)
{
    int max = *ptrarr[0];
    int i;

    for (i = 1; i < count; i++)
    {
        if (*ptrarr[i] > max)
            max = *ptrarr[i];
    }

    return max;
}
