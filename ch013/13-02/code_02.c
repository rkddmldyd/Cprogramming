// **********************************************
// 제 목 : 문자열의 대문자와 소문자 상호 변환
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
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }

        i++;
    }

    printf("변환결과: %s\n", str);

    return 0;
}
