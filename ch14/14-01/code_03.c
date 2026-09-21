// **********************************************
// 제 목 : 주소에 의한 호출로 세 정수 순환 교환
// 날 짜 : 2026년 9월 21일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* px, int* py, int* pz);

int main(void)
{
    int x, y, z;

    printf("정수x를 입력 하시오: ");
    if (scanf("%d", &x) != 1)
        return 1;

    printf("정수y를 입력 하시오: ");
    if (scanf("%d", &y) != 1)
        return 1;

    printf("정수z를 입력 하시오: ");
    if (scanf("%d", &z) != 1)
        return 1;

    printf("swap함수 호출 전 x=%d, y=%d, z=%d\n", x, y, z);
    swap(&x, &y, &z);
    printf("swap함수 호출 후 x=%d, y=%d, z=%d\n", x, y, z);

    return 0;
}

void swap(int* px, int* py, int* pz)
{
    int temp = *px;

    *px = *py;
    *py = *pz;
    *pz = temp;
}
