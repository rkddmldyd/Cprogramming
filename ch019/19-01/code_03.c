// **********************************************
// 제 목 : 함수 포인터를 이용한 계산기
// 날 짜 : 2026년 10월 7일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }
int Divide(int a, int b) { return a / b; }

void Calculate(int (*operation)(int, int))
{
    int a, b;
    printf("두개의 정수를 입력하시오 : ");
    if (scanf("%d %d", &a, &b) != 2)
        return;
    if (operation == Divide && b == 0)
    {
        printf("0으로 나눌 수 없습니다.\n");
        return;
    }
    printf("결과값: %d\n", operation(a, b));
}

int main(void)
{
    int choice;
    int (*operation)(int, int);

    printf("연산을 선택하시오(1:덧셈,2:뺄셈,3:곱셈,4:나눗셈) : ");
    if (scanf("%d", &choice) != 1)
        return 0;
    switch (choice)
    {
    case 1: operation = Add; break;
    case 2: operation = Subtract; break;
    case 3: operation = Multiply; break;
    case 4: operation = Divide; break;
    default:
        printf("잘못된 선택입니다.\n");
        return 0;
    }
    Calculate(operation);
    return 0;
}
