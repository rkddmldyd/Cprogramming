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
