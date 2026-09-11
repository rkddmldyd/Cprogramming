// **********************************************
// 제 목 : 포인터 표현을 이용한 성적 평균 계산
// 날 짜 : 2026년 9월 11일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int grade[5];
    int sum = 0, i, average;

    for (i = 0; i < 5; i++)
    {
        printf("성적을 입력하시오: ");
        if (scanf("%d", grade + i) != 1)
            return 1;
    }

    for (i = 0; i < 5; i++)
        sum += *(grade + i);

    average = (int)(sum / 5.0);
    printf("성적 평균= %d\n", average);

    return 0;
}
