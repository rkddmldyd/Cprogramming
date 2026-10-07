// **********************************************
// 제 목 : 이중 포인터로 최댓값과 최솟값의 주소를 구하는 프로그램
// 날 짜 : 2026년 10월 7일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MaxAndMin(int* arr, int len, int** pmax, int** pmin);

int main(void)
{
    int* maxPtr = NULL;
    int* minPtr = NULL;
    int arr[5] = { 10, 30, 50, 20, 40 };

    MaxAndMin(arr, 5, &maxPtr, &minPtr);

    printf("최댓값: %d\n", *maxPtr);
    printf("최솟값: %d\n", *minPtr);

    return 0;
}

void MaxAndMin(int* arr, int len, int** pmax, int** pmin)
{
    int i;

    *pmax = &arr[0];
    *pmin = &arr[0];

    for (i = 1; i < len; i++)
    {
        if (arr[i] > **pmax)
            *pmax = &arr[i];

        if (arr[i] < **pmin)
            *pmin = &arr[i];
    }
}
