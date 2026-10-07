// **********************************************
// 제 목 : 홀수는 배열 앞에서 짝수는 뒤에서 저장
// 날 짜 : 2026년 9월 29일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int data[10];
    int i, number;
    int front = 0, back = 9;

    printf("총 10개의 숫자 입력\n");
    for (i = 0; i < 10; i++)
    {
        printf("입력: ");
        if (scanf("%d", &number) != 1)
            return 1;

        if (number % 2 != 0)
        {
            data[front] = number;
            front++;
        }
        else
        {
            data[back] = number;
            back--;
        }
    }

    printf("배열 요소의 출력 :");
    for (i = 0; i < 10; i++)
        printf(" %d", data[i]);
    printf("\n");

    return 0;
}
