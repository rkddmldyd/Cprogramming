// **********************************************
// 제 목 : 달팽이 배열
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MakeSnail(int arr[][100], int n)
{
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int value = 1;
    int i;

    while (top <= bottom && left <= right)
    {
        for (i = left; i <= right; i++)
            arr[top][i] = value++;
        top++;
        for (i = top; i <= bottom; i++)
            arr[i][right] = value++;
        right--;
        if (top <= bottom)
        {
            for (i = right; i >= left; i--)
                arr[bottom][i] = value++;
            bottom--;
        }
        if (left <= right)
        {
            for (i = bottom; i >= top; i--)
                arr[i][left] = value++;
            left++;
        }
    }
}

int main(void)
{
    int arr[100][100];
    int n, i, j;
    printf("숫자를 입력하시오 : ");
    if (scanf("%d", &n) != 1)
        return 0;
    if (n < 1 || n > 100)
    {
        printf("1부터 100까지 입력하시오.\n");
        return 0;
    }
    MakeSnail(arr, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%6d", arr[i][j]);
        printf("\n");
    }
    return 0;
}
