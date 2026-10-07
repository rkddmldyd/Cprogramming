// **********************************************
// 제 목 : 0부터 99까지 난수 출력
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    printf("난수의 범위: 0부터 99까지\n");
    for (i = 0; i < 5; i++)
        printf("난수 출력: %d\n", rand() % 100);
    return 0;
}
