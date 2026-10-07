// **********************************************
// 제 목 : 2차원 배열의 회전
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ShowArray(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
}

void RotateArray(int arr[][4])
{
    int temp[4][4];
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[j][3 - i] = arr[i][j];
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            arr[i][j] = temp[i][j];
}

int main(void)
{
    int arr[4][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    int count;
    printf("처음 배열\n");
    ShowArray(arr);
    for (count = 1; count <= 3; count++)
    {
        RotateArray(arr);
        printf("\n%d도 회전\n", count * 90);
        ShowArray(arr);
    }
    return 0;
}
