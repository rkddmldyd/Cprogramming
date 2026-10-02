// **********************************************
// 제 목 : 2차원 배열의 최대값과 위치 구하기
// 날 짜 : 2026년 10월 2일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int arr[3][3] = { { -5, 2, 35 }, { -20, 5, 100 }, { -75, 5, -25 } };
    int max = arr[0][0];
    int row = 0, column = 0;
    int i, j;

    // 모든 행과 열을 검사하면서 최대값과 위치를 함께 저장
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                row = i;
                column = j;
            }

    printf("최대값은 %d\n", max);
    printf("위치는 %d행 %d열\n", row + 1, column + 1);
    return 0;
}
