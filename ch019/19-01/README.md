# 실습과제 1

## 문제

**1. 함수 선언, 호출, 정의를 각각 설명하라.**

* 선언은 함수의 반환형, 이름, 매개변수를 알리는 것이다.
* 호출은 함수에 인자를 전달하고 실행하는 것이다.
* 정의는 함수가 수행할 내용을 작성하는 것이다.

**2. 함수의 자료형은?**

반환형과 매개변수의 자료형으로 결정된다. `int Add(int, int)`의 함수형은 `int(int, int)`이다.

**3. 함수명의 자료형은?**

함수명을 주소로 사용하면 함수 포인터로 변환된다. Add의 주소를 받는 포인터의 자료형은 `int (*)(int, int)`이다.

**4. void 포인터의 용도는?**

여러 자료형의 변수 주소를 공통 매개변수로 전달할 때 사용한다.

**5. void 포인터에 간접참조 연산을 적용할 때 주의점은?**

가리키는 값의 자료형을 알 수 없으므로, 실제 자료형의 포인터로 변환한 뒤 역참조해야 한다.

**6. 강제형변환과 자동형변환을 설명하라.**

* 강제형변환은 `(double)num`처럼 변환할 자료형을 직접 지정하는 것이다.
* 자동형변환은 대입이나 연산 과정에서 자료형이 자동으로 바뀌는 것이다.

&nbsp;

# 실습과제 2

## 문제

함수 포인터와 void 포인터를 매개변수로 사용하는 인터넷 예제를 찾아 실행하고 설명한다.

## 소스코드 설명

```c
int Compare(const void* first, const void* second)
{
    int a = *(const int*)first;
    int b = *(const int*)second;
    return (a > b) - (a < b);
}

qsort(arr, 5, sizeof(arr[0]), Compare);
```

* [Microsoft qsort 예제](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/qsort?view=msvc-170)를 정수 배열 정렬에 적용했다.
* Compare 함수의 주소를 전달하여 배열을 오름차순으로 정렬한다. 두 주소는 int 포인터로 변환한 뒤 값을 비교한다.

```c
char str[7] = "aabbcc";
printf("복사 전: %s\n", str);
memmove(str + 2, str, 4);
printf("복사 후: %s\n", str);
```

* [Microsoft memmove 예제](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/memmove-wmemmove?view=msvc-170)를 참고했다.
* memmove는 목적지와 원본 주소를 void 포인터로 받는다. 겹치는 영역도 복사할 수 있어 결과는 aaaabb이다.

# 실행결과

<img width="1154" height="111" alt="result02" src="https://github.com/user-attachments/assets/bbd10d62-4d08-49aa-bef1-9d017d7cb36d" />

&nbsp;

# 실습과제 3

## 문제

함수 포인터를 이용하여 계산기를 만든다. 입력과 출력은 하나의 함수에서 처리하고, 연산은 각각의 함수로 작성한다.

## 소스코드 설명

```c
int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }
int Divide(int a, int b) { return a / b; }
```

* 각 함수는 두 정수를 받아 해당 연산의 결과를 반환한다. 나눗셈은 정수 나눗셈이다.

```c
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
```

* 선택한 함수의 주소를 받아 입력과 결과 출력을 처리한다. 0으로 나누는 경우에는 연산하지 않는다.

```c
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
```

* 선택한 연산의 함수 주소를 operation에 저장하고 Calculate에 전달한다.

# 실행결과

<img width="1154" height="123" alt="result03" src="https://github.com/user-attachments/assets/c4da3b2f-e8f5-44b4-9d8e-b5617e59803a" />

