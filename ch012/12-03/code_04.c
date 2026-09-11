// **********************************************
// 제 목 : 배열과 포인터의 다섯 가지 표현으로 실수 출력
// 날 짜 : 2026년 9월 11일
// 작성자 : 2600172 정준석
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    double arr[5];
    double* ptr = arr;
    double* temp;
    int i;

    // 포인터 덧셈연산을 이용하여 실수 5개 입력
    printf("5개의 실수를 입력하시오.\n");
    for (i = 0; i < 5; i++)
    {
        if (scanf("%lf", ptr + i) != 1)
            return 1;
    }

    // 각 배열 요소의 값에 2를 한 번씩 더하기
    for (i = 0; i < 5; i++)
        *(ptr + i) += 2.0;

    // 1. 배열명을 이용한 배열 표현
    printf("1. arr[i] : ");
    for (i = 0; i < 5; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    // 2. 배열명을 이용한 주소 표현
    printf("2. *(arr + i) : ");
    for (i = 0; i < 5; i++)
        printf("%.2f ", *(arr + i));
    printf("\n");

    // 3. 포인터 변수를 이용한 배열 표현
    printf("3. ptr[i] : ");
    for (i = 0; i < 5; i++)
        printf("%.2f ", ptr[i]);
    printf("\n");

    // 4. 포인터 변수를 이용한 주소 표현
    printf("4. *(ptr + i) : ");
    for (i = 0; i < 5; i++)
        printf("%.2f ", *(ptr + i));
    printf("\n");

    // 5. 증감연산자를 이용한 주소 표현
    temp = ptr;
    printf("5. *temp++ : ");
    for (i = 0; i < 5; i++)
        printf("%.2f ", *temp++);
    printf("\n");

    return 0;
}
