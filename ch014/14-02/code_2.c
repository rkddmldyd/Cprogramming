// **********************************************
// 제 목 : get_data 함수로 정수 5개를 배열에 저장하기
// 날 짜 : 2026년 9월 29일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_data(int* data, int n);

int main(void)
{
    int i, data[5];

    if (get_data(data, 5) == 0)
        return 1;

    for (i = 0; i < 5; i++)
        printf("%d번째 data: %d\n", i + 1, data[i]);

    return 0;
}

int get_data(int* data, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d번째 data를 입력하시오: ", i + 1);
        if (scanf("%d", data + i) != 1)
            return 0;
    }

    return 1;
}
