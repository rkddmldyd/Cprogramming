// **********************************************
// 제 목 : 포인터 값 계산과 변경
// 날 짜 : 2026년 9월 9일
// 작성자 : 2600172 정준석
// **********************************************


#include <stdio.h>

int main(void)
{
    int num1 = 25, num2 = 40;

    int* ptr1 = &num1;
    int* ptr2 = &num2;
    int* small;
    int* big;
    int* temp;

    small = (*ptr1 < *ptr2) ? ptr1 : ptr2;
    big = (*ptr1 > *ptr2) ? ptr1 : ptr2;

    *small += 10;
    *big -= 10;

    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;

    printf("num1의 값: %d\n", num1);
    printf("num2 값: %d\n", num2);
    printf("ptr1이 가리키는 값: %d\n", *ptr1);
    printf("ptr2가 가리키는 값: %d\n", *ptr2);

    return 0;
}
