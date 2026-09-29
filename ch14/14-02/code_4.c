// **********************************************
// 제 목 : 정수 10개의 홀수와 짝수를 함수로 나누어 출력
// 날 짜 : 2026년 9월 29일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_odd(const int* array, int n);
void print_even(const int* array, int n);

int main(void)
{
    int data[10];
    int i;

    printf("총 10개의 숫자 입력\n");
    for (i = 0; i < 10; i++)
    {
        printf("입력: ");
        if (scanf("%d", data + i) != 1)
            return 1;
    }

    print_odd(data, 10);
    print_even(data, 10);

    return 0;
}

void print_odd(const int* array, int n)
{
    int i, count = 0;

    printf("홀수 출력: ");
    for (i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            if (count > 0)
                printf(", ");
            printf("%d", array[i]);
            count++;
        }
    }
    printf("\n");
}

void print_even(const int* array, int n)
{
    int i, count = 0;

    printf("짝수 출력: ");
    for (i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            if (count > 0)
                printf(", ");
            printf("%d", array[i]);
            count++;
        }
    }
    printf("\n");
}
