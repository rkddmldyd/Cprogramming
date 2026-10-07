// **********************************************
// 제 목 : 함수 포인터와 void 포인터 활용
// 날 짜 : 2026년 10월 7일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void* first, const void* second)
{
    int a = *(const int*)first;
    int b = *(const int*)second;
    return (a > b) - (a < b);
}

int main(void)
{
    int arr[5] = { 30, 10, 50, 20, 40 };
    char str[7] = "aabbcc";
    int i;

    qsort(arr, 5, sizeof(arr[0]), Compare);
    printf("정렬 결과: ");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("복사 전: %s\n", str);
    memmove(str + 2, str, 4);
    printf("복사 후: %s\n", str);
    return 0;
}
