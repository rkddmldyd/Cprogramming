// **********************************************
// 제 목 : 정수 5개의 최댓값을 함수로 구하기
// 날 짜 : 2026년 9월 29일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_max(const int* array, int n);

int main(void)
{
    int data[5];
    int i, max;

    printf("정수5개를 입력 하시오.\n");
    for (i = 0; i < 5; i++)
    {
        if (scanf("%d", data + i) != 1)
            return 1;
    }

    max = get_max(data, 5);
    printf("최대값은 %d입니다.\n", max);

    return 0;
}

int get_max(const int* array, int n)
{
    int i;
    int max = *array;

    for (i = 1; i < n; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
    }

    return max;
}
