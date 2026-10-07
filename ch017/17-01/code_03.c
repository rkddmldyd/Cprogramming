// **********************************************
// 제 목 : 포인터 배열에 저장된 문자열을 출력하는 프로그램
// 날 짜 : 2026년 10월 7일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수선언
void prn_str(char** ptrarr, int count);

int main(void)
{
    char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" };
    int count;

    count = (int)(sizeof(ptrarr) / sizeof(ptrarr[0]));
    prn_str(ptrarr, count); // 함수호출

    return 0;
}

// 함수정의
void prn_str(char** ptrarr, int count)
{
    int i;

    for (i = 0; i < count; i++)
        printf("%s\n", ptrarr[i]);
}
