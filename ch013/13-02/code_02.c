// **********************************************
// 제 목 : 문자열에서 대문자는 소문자로, 소문자로 대문자로 변경
// 날 짜 : 2026년 9월 17일
// 작성자 : 2600172정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    char str[100];
    int i = 0;
    char cstr[100];

    printf("문자열을 입력하시오: ");
    scanf("%s", str);

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cstr[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            cstr[i] = str[i] + 32;
        }
        else
        {
            cstr[i] = str[i];
        }

        i++;
    }

    cstr[i] = '\0';

    printf("변환결과: %s", cstr);

    return 0;
}
