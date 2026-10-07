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

* `ptr`에는 num의 주소 100이 저장된다. ptr의 자료형은 `double*`이다.
* `dptr`에는 ptr의 주소 300이 저장된다. dptr의 자료형은 `double**`이다.
* `&ptr`은 포인터 변수 ptr 자신의 주소이므로 300이며 자료형은 `double**`이다.
* `&dptr`은 이중 포인터 변수 dptr 자신의 주소이므로 500이며 자료형은 `double***`이다.
* `*ptr`은 ptr이 가리키는 num의 값 6.28이며 자료형은 double이다.
* `*dptr`은 dptr이 가리키는 ptr의 값 100이며 자료형은 `double*`이다.
* `**dptr`은 ptr을 다시 간접참조한 num의 값 6.28이며 자료형은 double이다.

&nbsp;

# 실습과제 2

## 문제

포인터 배열 ptrarr을 전달받아 가리키는 정수 중 최댓값을 반환하는 get_max 함수의 선언과 정의를 추가한다. num1, num2, num3이 각각 50, 20, 30일 때 최댓값 50을 출력한다.

## 소스코드 설명

```c
int get_max(int** ptrarr, int count);
```

* 포인터 배열의 각 요소는 int*형이다. 함수에 배열명을 전달하면 첫 번째 포인터 요소의 주소를 받으므로 매개변수를 int**형으로 선언한다.
* count는 비교할 배열 요소의 개수이며, 최댓값을 int형으로 반환한다.

```c
int num1 = 50, num2 = 20, num3 = 30;
int* ptrarr[3] = { &num1, &num2, &num3 };
int max;
```

* 세 정수형 변수에 50, 20, 30을 저장한다.
* ptrarr의 각 요소에는 num1, num2, num3의 주소를 저장한다.
* 함수가 반환할 최댓값을 저장하기 위해 max를 선언한다.

```c
max = get_max(ptrarr, 3);
printf("최댓값:%d\n", max);
```

* 포인터 배열과 요소 개수 3을 get_max 함수에 전달한다.
* 반환된 최댓값을 max에 저장한 후 출력한다.

```c
int max = *ptrarr[0];
int i;
```

* 첫 번째 포인터가 가리키는 정수값을 최댓값의 초기값으로 사용한다.
* 초기값을 0으로 정하지 않으므로 모든 정수가 음수여도 올바르게 비교할 수 있다.

```c
for (i = 1; i < count; i++)
{
    if (*ptrarr[i] > max)
        max = *ptrarr[i];
}
```

* 첫 번째 값은 이미 max에 저장했으므로 두 번째 요소부터 비교한다.
* ptrarr[i]는 정수의 주소이고, *ptrarr[i]는 그 주소에 저장된 정수값이다.
* 현재 값이 max보다 크면 max를 현재 값으로 변경한다.

```c
return max;
```

* 모든 값을 비교한 후 최댓값을 main 함수로 반환한다.

# 실행결과

<img width="1707" height="1019" alt="image" src="https://github.com/user-attachments/assets/9392076a-ccc6-47d9-a4e5-88d4afbb0d49" />

&nbsp;

# 실습과제 3

## 문제

문자열 포인터 배열 ptrarr을 전달받아 eagle, tiger, lion, squirrel을 한 줄씩 출력하는 prn_str 함수의 선언과 정의를 추가한다.

## 소스코드 설명

```c
void prn_str(char** ptrarr, int count);
```

* 문자열의 시작 주소를 저장하는 배열의 요소는 char*형이다.
* 배열명을 인자로 전달하면 첫 번째 char* 요소의 주소를 받으므로 매개변수를 char**형으로 선언한다.
* 출력만 하는 함수이므로 반환형을 void로 선언한다.

```c
char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" };
int count;
```

* 네 문자열의 시작 주소를 포인터 배열에 저장한다.
* 문자열 리터럴은 출력에만 사용하며 내용을 변경하지 않는다.

```c
count = (int)(sizeof(ptrarr) / sizeof(ptrarr[0]));
prn_str(ptrarr, count);
```

* 배열 전체의 크기를 요소 하나의 크기로 나누어 요소 개수 4를 구한다.
* sizeof 연산 결과를 count의 자료형인 int로 변환한다.
* 배열과 요소 개수를 prn_str 함수에 전달한다.

```c
void prn_str(char** ptrarr, int count)
{
    int i;

    for (i = 0; i < count; i++)
        printf("%s\n", ptrarr[i]);
}
```

* i를 선언하고 첫 번째 요소부터 마지막 요소까지 반복한다.
* ptrarr[i]는 해당 문자열의 시작 주소이다.
* %s로 문자열을 출력하고 \n으로 줄을 바꾼다.
* 네 문자열을 출력한 뒤 함수를 종료한다.

# 실행결과

<img width="1707" height="1019" alt="image" src="https://github.com/user-attachments/assets/07f1fe80-fb06-4783-b66f-73d3b0402979" />

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

* 첫 번째와 다섯 번째 줄은 프로그램 정보의 시작과 끝을 표시하는 주석이다.
* 두 번째 줄은 프로그램 제목, 세 번째 줄은 작성 날짜, 네 번째 줄은 학번과 이름을 기록하는 주석이다. 주석은 실행에 영향을 주지 않는다.
* `#define _CRT_SECURE_NO_WARNINGS`는 Visual Studio의 CRT 보안 관련 사용 중단 경고를 비활성화하는 매크로이다.
* `#include <stdio.h>`는 printf 함수와 NULL 매크로를 사용하기 위해 표준 입출력 헤더를 포함한다.

```c
// 함수선언
void MaxAndMin(int* arr, int len, int** pmax, int** pmin);
```

* `// 함수선언`은 다음 줄이 함수 원형임을 표시하는 주석이다.
* MaxAndMin은 값을 반환하지 않으므로 반환형을 void로 선언한다.
* arr은 배열 첫 요소의 주소를 받는 int*형 매개변수이고, len은 배열의 길이를 받는다.
* pmax와 pmin은 main 함수의 int*형 포인터 변수 자체를 변경하기 위해 그 주소를 받는 int**형 매개변수이다.
* 선언 끝의 세미콜론은 함수 원형의 끝을 표시한다.

```c
int main(void)
{
    int* maxPtr = NULL;
    int* minPtr = NULL;
    int arr[5] = { 10, 30, 50, 20, 40 };
```

* `int main(void)`는 매개변수가 없고 종료 상태를 int형으로 반환하는 메인함수를 정의한다.
* `{`는 main 함수 본문의 시작이다.
* maxPtr은 최댓값의 주소를 저장할 int*형 포인터이다. 함수 호출 전에는 NULL로 초기화하며 간접참조하지 않는다.
* minPtr은 최솟값의 주소를 저장할 int*형 포인터이며 NULL로 초기화한다.
* arr은 길이가 5인 int형 배열이다. 각 요소를 10, 30, 50, 20, 40으로 초기화한다.

```c
MaxAndMin(arr, 5, &maxPtr, &minPtr); // 함수호출
```

* arr은 첫 번째 요소의 주소로 변환되어 전달되고, 5는 요소 개수이다.
* maxPtr과 minPtr의 현재 값 대신 `&maxPtr`, `&minPtr`로 포인터 변수 자신의 주소를 전달한다.
* pmax에는 maxPtr의 주소가, pmin에는 minPtr의 주소가 저장된다. 함수 안에서 `*pmax`, `*pmin`에 대입하면 main 함수의 두 포인터를 변경할 수 있다.
* `// 함수호출`은 이 줄이 함수 호출임을 설명하는 주석이다.

```c
printf("최댓값: %d\n", *maxPtr);
printf("최솟값: %d\n", *minPtr);

return 0;
}
```

* 첫 번째 printf는 maxPtr이 가리키는 배열 요소의 값 50을 출력한다. `%d`는 정수 출력, `\n`은 줄바꿈이다.
* 두 번째 printf는 minPtr이 가리키는 배열 요소의 값 10을 출력한다.
* `return 0;`은 프로그램이 정상 종료했음을 알린다.
* `}`는 main 함수 본문의 끝이다.

```c
// 함수정의
void MaxAndMin(int* arr, int len, int** pmax, int** pmin)
{
    int i;
```

* `// 함수정의`는 다음 부분이 함수 본문임을 표시하는 주석이다.
* MaxAndMin의 이름과 반환형, 매개변수의 자료형은 앞의 함수 원형과 일치한다.
* `{`는 MaxAndMin 함수 본문의 시작이며, `int i;`는 반복문에서 사용할 인덱스를 선언한다.
* 이 함수에는 길이가 1 이상인 배열과 유효한 포인터 변수의 주소를 전달한다. main에서는 길이가 5인 배열을 전달한다.

```c
*pmax = &arr[0];
*pmin = &arr[0];
```

* pmax를 한 번 간접참조하면 main의 maxPtr이다. 여기에 첫 요소의 주소를 저장하여 최댓값 후보로 정한다.
* pmin을 한 번 간접참조하면 main의 minPtr이다. 여기에 첫 요소의 주소를 저장하여 최솟값 후보로 정한다.
* 최댓값과 최솟값을 0으로 시작하지 않고 첫 요소로 시작하므로 모든 값이 음수여도 올바르게 비교할 수 있다.

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

* for문은 i를 1로 초기화하고 i가 len보다 작은 동안 반복한다. 반복이 끝날 때마다 i를 1 증가시킨다. 첫 요소는 이미 후보로 정했으므로 두 번째 요소부터 비교한다.
* 첫 번째 `{`는 반복문 본문의 시작이다.
* `arr[i] > **pmax`는 현재 요소의 값과 maxPtr이 가리키는 최댓값 후보를 비교한다. pmax를 두 번 간접참조해야 배열 요소의 정수값을 얻는다.
* 현재 값이 더 크면 `*pmax = &arr[i];`로 main의 maxPtr에 현재 요소의 주소를 저장한다. 배열의 정수값을 대입하는 것이 아니다.
* `arr[i] < **pmin`은 현재 요소의 값과 minPtr이 가리키는 최솟값 후보를 비교한다.
* 현재 값이 더 작으면 `*pmin = &arr[i];`로 main의 minPtr에 현재 요소의 주소를 저장한다.
* 첫 번째 `}`는 반복문 본문의 끝이고, 마지막 `}`는 MaxAndMin 함수 본문의 끝이다. 반환형이 void이므로 반환값 없이 main으로 돌아간다.
* 빈 줄은 코드의 구역을 구분하기 위한 것으로 실행에는 영향을 주지 않는다.

## 시간에 따른 메모리 상태

설명을 위해 int의 크기는 4바이트, arr의 시작 주소는 1000, maxPtr의 주소는 2000, minPtr의 주소는 2010이라고 가정한다. 아래 주소는 이해를 위한 가상 주소이며 실제 실행 주소는 달라질 수 있다.

```text
main 함수의 배열

주소        1000        1004        1008        1012        1016
         +----------+----------+----------+----------+----------+
arr      |    10    |    30    |    50    |    20    |    40    |
         +----------+----------+----------+----------+----------+
요소       arr[0]     arr[1]     arr[2]     arr[3]     arr[4]

함수 호출 전
maxPtr (주소 2000) : NULL
minPtr (주소 2010) : NULL

함수 호출 직후
arr 매개변수 : 1000
len 매개변수 : 5
pmax ──> maxPtr (주소 2000)
pmin ──> minPtr (주소 2010)

첫 요소의 주소로 초기화한 뒤
pmax ──> maxPtr [1000] ──> arr[0] [10]
pmin ──> minPtr [1000] ──> arr[0] [10]

모든 비교를 마친 뒤
pmax ──> maxPtr [1008] ──> arr[2] [50]
pmin ──> minPtr [1000] ──> arr[0] [10]

함수 종료 후
maxPtr [1008] ──> arr[2] [50]
minPtr [1000] ──> arr[0] [10]
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

* pmax에 저장된 값 2000은 maxPtr 자신의 주소이고, `*pmax`는 maxPtr에 저장된 배열 요소의 주소이다. `**pmax`는 그 요소의 정수값이다.
* pmin에 저장된 값 2010은 minPtr 자신의 주소이고, `*pmin`은 minPtr에 저장된 배열 요소의 주소이다. `**pmin`은 그 요소의 정수값이다.
* 함수가 끝나면 매개변수 arr, len, pmax, pmin과 지역 변수 i는 소멸한다. main의 배열과 두 포인터는 유지되므로 반환 후에도 최댓값과 최솟값을 출력할 수 있다.
* 최댓값이나 최솟값이 여러 개이면 엄격한 `>`, `<` 비교를 사용하므로 먼저 나온 요소의 주소를 유지한다.

# 실행결과

<img width="1707" height="1019" alt="image" src="https://github.com/user-attachments/assets/6f9e77a2-9926-4b5a-828d-ce9bbc195955" />
