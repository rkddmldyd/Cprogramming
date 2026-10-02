// **********************************************
// 제 목 : 첫 문자를 비교하여 사전에서 마지막 문자열 구하기
// 날 짜 : 2026년 10월 2일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char str[4][10];
    int i, last = 0;

    for (i = 0; i < 4; i++)
    {
        printf("%d번째 문자열 입력: ", i + 1);
        if (scanf("%9s", &str[i][0]) != 1)
            return 1;
    }

    // 과제 조건에 따라 strcmp 없이 첫 문자만 비교
    for (i = 1; i < 4; i++)
        if (str[i][0] > str[last][0])
            last = i;

    printf("사전에서 제일 뒤에 나오는 문자열: %s\n", &str[last][0]);
    return 0;
}
