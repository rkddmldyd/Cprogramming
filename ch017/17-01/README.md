# 실습과제 1

## 문제

다음 변수가 그림처럼 할당될 때 수식의 결과값과 결과값의 자료형을 구한다. num의 주소는 100, ptr의 주소는 300, dptr의 주소는 500이라고 가정한다.

```c
double num = 6.28;
double* ptr = &num;
double** dptr = &ptr;
```

|수식|결과값|결과값의 자료형|
|------|---|---|
|ptr|100|double*|
|dptr|300|double**|
|&ptr|300|double**|
|&dptr|500|double***|
|*ptr|6.28|double|
|*dptr|100|double*|
|**dptr|6.28|double|

* `ptr`와 `dptr`에는 각각 num과 ptr의 주소가 저장된다.
* `*ptr`과 `**dptr`은 num의 값이고, `*dptr`은 ptr에 저장된 주소이다.

&nbsp;

# 실습과제 2

## 문제

포인터 배열 ptrarr을 전달받아 가리키는 정수 중 최댓값을 반환하는 get_max 함수의 선언과 정의를 추가한다. num1, num2, num3이 각각 50, 20, 30일 때 최댓값 50을 출력한다.

## 소스코드 설명

```c
int get_max(int** ptrarr, int count);
```

* 포인터 배열을 받으므로 매개변수는 int**로 선언한다.
* count는 배열 요소의 개수이다.

```c
int num1 = 50, num2 = 20, num3 = 30;
int* ptrarr[3] = { &num1, &num2, &num3 };
int max;
```

* 세 정수의 주소를 ptrarr에 저장한다.

```c
max = get_max(ptrarr, 3);
printf("최댓값:%d\n", max);
```

* get_max에 배열을 전달하고 반환된 최댓값을 출력한다.

```c
int max = *ptrarr[0];
int i;
```

* 첫 번째 정수값을 max의 초기값으로 정한다.

```c
for (i = 1; i < count; i++)
{
    if (*ptrarr[i] > max)
        max = *ptrarr[i];
}
```

* 나머지 값을 비교하여 더 큰 값이 있으면 max를 바꾼다.

```c
return max;
```

* 최댓값을 반환한다.

# 실행결과

<img width="865" height="59" alt="image" src="https://github.com/user-attachments/assets/6d03faca-bf2e-4ad5-bfad-bd19603cc786" />


&nbsp;

# 실습과제 3

## 문제

문자열 포인터 배열 ptrarr을 전달받아 eagle, tiger, lion, squirrel을 한 줄씩 출력하는 prn_str 함수의 선언과 정의를 추가한다.

## 소스코드 설명

```c
void prn_str(char** ptrarr, int count);
```

* 문자열 포인터 배열을 받도록 char**로 선언한다.

```c
char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" };
int count;
```

* 네 문자열의 주소를 배열에 저장한다.

```c
count = (int)(sizeof(ptrarr) / sizeof(ptrarr[0]));
prn_str(ptrarr, count);
```

* 배열 요소의 개수를 구해 prn_str에 전달한다.

```c
void prn_str(char** ptrarr, int count)
{
    int i;

    for (i = 0; i < count; i++)
        printf("%s\n", ptrarr[i]);
}
```

* 배열에 저장된 문자열을 한 줄씩 출력한다.

# 실행결과

<img width="863" height="89" alt="image" src="https://github.com/user-attachments/assets/eb855f25-6932-4539-b178-c812d18d1f61" />


&nbsp;

# 실습과제 4

## 문제

교재 368쪽 문제 17-1을 풀고 소스코드의 모든 라인을 메모리 그림과 함께 설명한다. 길이가 5인 int형 배열과 두 포인터 maxPtr, minPtr을 선언하고 MaxAndMin 함수에 전달한다. 함수 호출 후 maxPtr에는 최댓값이 저장된 배열 요소의 주소를, minPtr에는 최솟값이 저장된 배열 요소의 주소를 저장한다.

## 소스코드 설명

```c
// **********************************************
// 제 목 : 이중 포인터로 최댓값과 최솟값의 주소를 구하는 프로그램
// 날 짜 : 2026년 10월 7일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
```

* 위 주석에는 제목, 날짜, 학번과 이름을 적었다.
* 매크로는 Visual Studio의 보안 관련 경고를 막고, stdio.h는 printf와 NULL을 사용하기 위해 포함한다.

```c
void MaxAndMin(int* arr, int len, int** pmax, int** pmin);
```

* 반환형은 void이며, arr은 배열의 주소, len은 배열의 길이를 받는다.
* pmax와 pmin은 main의 포인터를 변경해야 하므로 int**로 선언한다.

```c
int main(void)
{
    int* maxPtr = NULL;
    int* minPtr = NULL;
    int arr[5] = { 10, 30, 50, 20, 40 };
```

* main 함수의 시작이다. maxPtr과 minPtr을 선언하고 NULL로 초기화한다.
* arr에는 정수 5개를 저장한다.

```c
MaxAndMin(arr, 5, &maxPtr, &minPtr);
```

* 배열과 두 포인터 변수의 주소를 함수에 전달한다.
* `*pmax`, `*pmin`에 대입하면 main의 maxPtr, minPtr이 변경된다.

```c
printf("최댓값: %d\n", *maxPtr);
printf("최솟값: %d\n", *minPtr);

return 0;
}
```

* 두 포인터가 가리키는 값을 출력한다.
* return 0으로 정상 종료하고 main 함수가 끝난다.

```c
void MaxAndMin(int* arr, int len, int** pmax, int** pmin)
{
    int i;
```

* MaxAndMin 함수의 정의이며, i는 반복문에 사용할 변수이다.

```c
*pmax = &arr[0];
*pmin = &arr[0];
```

* 첫 요소의 주소를 maxPtr과 minPtr에 저장한다.

```c
for (i = 1; i < len; i++)
{
    if (arr[i] > **pmax)
        *pmax = &arr[i];

    if (arr[i] < **pmin)
        *pmin = &arr[i];
}
}
```

* i=1부터 마지막 요소까지 하나씩 비교한다.
* `**pmax`, `**pmin`은 현재 최대·최소 값이다.
* 더 큰 값이나 더 작은 값이 있으면 해당 요소의 주소로 포인터를 바꾼다.
* 두 닫는 중괄호는 반복문과 함수의 끝이다.

## 시간에 따른 메모리 상태

주소는 설명을 위해 가정한 값이다. int의 크기는 4바이트로 둔다.

```text
주소       1000   1004   1008   1012   1016
arr       [10]   [30]   [50]   [20]   [40]
요소      arr[0] arr[1] arr[2] arr[3] arr[4]

호출 전
maxPtr (주소 2000) : NULL
minPtr (주소 2010) : NULL

함수 안에서 초기화한 뒤
pmax → maxPtr [1000] → arr[0] [10]
pmin → minPtr [1000] → arr[0] [10]

비교가 끝난 뒤
pmax → maxPtr [1008] → arr[2] [50]
pmin → minPtr [1000] → arr[0] [10]
```

|실행 시점|비교하는 값|maxPtr에 저장된 주소|minPtr에 저장된 주소|최댓값 후보|최솟값 후보|
|------|---:|---:|---:|---:|---:|
|함수 호출 전|-|NULL|NULL|-|-|
|첫 요소로 초기화|10|1000|1000|10|10|
|i=1 비교 후|30|1004|1000|30|10|
|i=2 비교 후|50|1008|1000|50|10|
|i=3 비교 후|20|1008|1000|50|10|
|i=4 비교 후|40|1008|1000|50|10|
|함수 종료 후|-|1008|1000|50|10|

* pmax와 pmin은 main의 포인터 변수 주소를 가리킨다.
* 함수가 끝나도 maxPtr과 minPtr에 저장된 주소는 유지된다.

# 실행결과

<img width="859" height="65" alt="image" src="https://github.com/user-attachments/assets/a67d48ab-a63f-4257-8b8b-338a80da95e1" />
