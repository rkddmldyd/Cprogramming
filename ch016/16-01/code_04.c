// **********************************************
// 제 목 : 네 문자열의 길이 직접 구하기
// 날 짜 : 2026년 10월 2일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char str[4][10];
    int i, length;

    for (i = 0; i < 4; i++)
    {
        printf("%d번째 문자열 입력: ", i + 1);
        if (scanf("%9s", &str[i][0]) != 1)
            return 1;
    }

    // strlen 없이 문자열 끝의 널 문자를 만날 때까지 계산
    for (i = 0; i < 4; i++)
    {
        length = 0;
        while (str[i][length] != '\0')
            length++;
        printf("%d번째 문자열 길이: %d\n", i + 1, length);
    }
    return 0;
}
