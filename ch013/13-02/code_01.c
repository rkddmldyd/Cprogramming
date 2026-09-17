// **********************************************
// 제 목 : n번째 문자 출력
// 날 짜 : 2026년 9월 17일
// 작성자 : 2600172정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
	char str[100];

	printf("문자열을 입력하시오: ");
	scanf("%s", str);

	int n = strlen(str);

	for (int i = 0; i < n; i++)
	{
		printf("%d번째문자 %c \n", i+1, str[i]);
	}

	return 0;
}
