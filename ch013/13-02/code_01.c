// **********************************************
// 제 목 : 널문자를 이용한 문자열의 각 문자 출력
// 날 짜 : 2026년 9월 18일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char str[100];
    int i = 0;

    printf("문자열을 입력하시오: ");
    if (scanf("%99s", str) != 1)
        return 1;

    while (str[i] != '\0')
    {
        printf("%d번째문자 %c\n", i + 1, str[i]);
        i++;
    }

    return 0;
}
