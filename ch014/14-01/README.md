# 실습과제 1

**1. 함수의 인자와 매개변수의 차이를 설명하라.**

인자는 함수를 호출하는 쪽에서 함수에 전달하는 값이고, 매개변수는 호출된 함수가 그 값을 받기 위해 선언하는 지역 변수이다.

```c
int result = add2(number);
```

* `number`는 add2 함수를 호출할 때 전달하는 인자이다.

```c
int add2(int value)
```

* `value`는 인자값을 받는 매개변수이다.
* 값에 의한 호출에서는 number의 값이 value에 복사되므로 두 변수는 서로 다른 메모리 공간을 사용한다.
* 주소에 의한 호출에서는 인자로 변수의 주소를 전달하고, 매개변수는 그 주소를 저장할 포인터로 선언한다.

&nbsp;

**2. 함수가 호출될 때 컴퓨터에 의해 자동으로 실행되는 2가지를 설명하라.**

함수가 호출되면 컴퓨터는 다음 두 과정을 자동으로 실행한다.

1. 호출된 함수에서 사용할 매개변수를 메모리에 할당한다.
2. 호출할 때 전달한 인자값으로 매개변수를 초기화한다.

예를 들어 `add2(number)`를 호출하면 add2 함수의 매개변수 value가 새로 생성되고, number의 값이 value에 복사된다. 함수가 종료되면 매개변수는 지역 변수이므로 메모리에서 소멸한다.

&nbsp;

**3. 값에 의한 함수 호출방식의 문제점을 설명하라.**

값에 의한 호출은 인자의 값을 매개변수에 복사한다. 따라서 함수 안에서 매개변수를 변경해도 호출한 함수의 원본 변수는 변경되지 않는다.

```c
void add2(int value)
{
    value += 2;
}
```

number가 15일 때 value는 15로 초기화되고 17로 변경되지만, number와 value는 별개의 변수이다. 함수가 끝나면 value는 소멸하며 number는 계속 15를 저장한다. 함수 밖의 원본 변수를 직접 변경해야 하는 작업에는 값에 의한 호출만 사용할 수 없다는 문제가 있다.

다만 계산 결과 하나를 반환할 수 있는 경우에는 `number = add2(number);`처럼 반환값을 원본 변수에 다시 저장하여 해결할 수 있다.

&nbsp;

**4. 주소에 의한 함수 호출방식이 필요한 경우를 설명하라.**

호출된 함수가 다른 함수에 선언된 원본 변수의 값을 직접 변경해야 할 때 주소에 의한 호출이 필요하다.

```c
void add2(int* value)
{
    *value += 2;
}
```

* 호출할 때 `add2(&number)`처럼 number의 주소를 전달한다.
* 포인터 매개변수 value는 number의 주소를 저장한다.
* `*value`로 그 주소를 간접참조하면 main 함수의 number를 직접 변경할 수 있다.
* 두 개 이상의 원본 값을 한 함수에서 변경해야 하는 swap 함수나, 입력받은 값을 호출한 함수의 변수에 저장하는 scanf 함수에서 주소 전달을 사용한다.

&nbsp;

# 실습과제 2

## 문제

값에 의한 호출로 작성된 add2 함수에서는 매개변수만 2 증가하고 main 함수의 number는 변경되지 않는다. 그 이유를 메모리 상태로 설명하고, 주소에 의한 호출을 이용하여 number가 실제로 2 증가하도록 수정한다.

## 기존 코드가 원하는 대로 동작하지 않는 이유

|실행 시점|main 함수의 number|add2 함수의 value|
|------|---:|---:|
|add2 호출 전|15|존재하지 않음|
|add2 호출 직후|15|15|
|`value += 2` 실행 후|15|17|
|add2 종료 후|15|소멸|

값에 의한 호출에서는 number의 값 15만 value에 복사된다. value를 17로 변경해도 별도의 메모리 공간에 있는 number는 15로 유지되고, add2 함수가 끝나면 value의 17도 사라진다.

## 소스코드 설명

```c
void add2(int* value);
```

* 정수형 변수의 주소를 받을 수 있도록 매개변수를 int형 포인터로 선언한다.
* main 함수보다 뒤에서 add2 함수를 정의하므로 함수 원형을 먼저 선언한다.

```c
int number;

printf("정수를 입력 하시오: ");
if (scanf("%d", &number) != 1)
    return 1;
```

* 정수를 저장할 number를 선언하고 키보드로 값을 입력받는다.
* 입력에 실패하면 1을 반환하고 프로그램을 종료한다.

```c
add2(&number);
printf("2만큼 증가한 값: %d\n", number);
```

* 주소 연산자 `&`를 사용하여 number의 주소를 add2 함수에 전달한다.
* add2가 원본 값을 변경한 뒤 number를 출력한다.

```c
void add2(int* value)
{
    *value += 2;
}
```

* value에 저장된 주소를 간접참조하여 main 함수의 number에 2를 더한다.

# 실행결과

<img width="867" height="77" alt="image" src="https://github.com/user-attachments/assets/3dbad48b-a2e4-4997-978e-fade39a6f22e" />

&nbsp;

# 실습과제 3

## 문제

값에 의한 호출을 사용하여 매개변수의 값에 2를 더한 뒤 반환하고, main 함수에서 반환값을 받아 처리한다. 함수의 선언, 호출, 정의를 모두 사용한다.

## 소스코드 설명

```c
int add2(int value);
```

* add2 함수가 계산 결과를 int형으로 반환하고 int형 값을 매개변수로 받는다고 선언한다.

```c
number = add2(number);
```

* number의 값을 인자로 전달한다.
* add2가 반환한 결과를 number에 다시 저장하므로 main 함수의 number가 변경된다.

```c
int add2(int value)
{
    return value + 2;
}
```

* 매개변수 value에 2를 더한 값을 호출한 곳으로 반환한다.
* value는 number의 복사본이지만 계산 결과를 반환하므로 원본 변수에서 결과를 사용할 수 있다.

```c
printf("2만큼 증가한 값: %d\n", number);
return 0;
```

* 반환값을 저장한 number를 출력하고 메인함수를 정상 종료한다.

# 실행결과

<img width="871" height="70" alt="image" src="https://github.com/user-attachments/assets/e8899d6d-5386-4912-b220-31ae90f32b3f" />

&nbsp;

# 실습과제 4

## 문제

세 정수 x, y, z를 입력받고 swap 함수를 이용하여 x에는 y의 원래 값, y에는 z의 원래 값, z에는 x의 원래 값이 저장되도록 순환 교환한다. 함수의 선언, 호출, 정의를 모두 사용한다.

## 소스코드 설명

```c
void swap(int* px, int* py, int* pz);
```

* 세 정수의 원본 값을 변경하기 위해 세 개의 int형 포인터를 매개변수로 선언한다.

```c
int x, y, z;
```

* 키보드로 입력받을 세 정수를 저장할 변수를 선언한다.

```c
printf("swap함수 호출 전 x=%d, y=%d, z=%d\n", x, y, z);
swap(&x, &y, &z);
printf("swap함수 호출 후 x=%d, y=%d, z=%d\n", x, y, z);
```

* 교환 전 값을 출력한다.
* x, y, z의 주소를 swap 함수에 전달하여 원본 값을 변경한다.
* 교환이 끝난 뒤 변경된 값을 출력한다.

```c
void swap(int* px, int* py, int* pz)
{
    int temp = *px;

    *px = *py;
    *py = *pz;
    *pz = temp;
}
```

* x의 원래 값을 잃지 않도록 temp에 저장한다.
* y의 원래 값을 x에, z의 원래 값을 y에 저장한다.
* 마지막으로 temp에 보관한 x의 원래 값을 z에 저장한다.

## 시간에 따른 메모리 상태

설명을 위해 x, y, z의 주소를 각각 100, 104, 108이라고 가정한다.

|실행 시점|x|y|z|px|py|pz|temp|
|------|---:|---:|---:|---:|---:|---:|---:|
|swap 호출 전|10|20|30|-|-|-|-|
|swap 호출 직후|10|20|30|100|104|108|미정|
|`temp = *px` 후|10|20|30|100|104|108|10|
|`*px = *py` 후|20|20|30|100|104|108|10|
|`*py = *pz` 후|20|30|30|100|104|108|10|
|`*pz = temp` 후|20|30|10|100|104|108|10|
|swap 종료 후|20|30|10|소멸|소멸|소멸|소멸|

포인터 매개변수에는 x, y, z의 주소가 저장되므로 간접참조를 통해 main 함수의 원본 값이 변경된다. swap 함수가 끝나면 매개변수와 temp는 소멸하지만 x, y, z에 저장된 변경 결과는 유지된다.

# 실행결과

<img width="862" height="118" alt="image" src="https://github.com/user-attachments/assets/d2909ef1-7c46-4cce-a327-7ebd0e2d2244" />

&nbsp;

# 실습과제 5

## 문제

num에 저장된 값을 100배 하는 함수를 값에 의한 호출과 주소에 의한 호출로 각각 작성한다. 두 방식의 차이를 확인하고 원본 num을 실제로 100배 하는 방식이 무엇인지 설명한다.

## 소스코드 설명

```c
void multiply_value(int value);
void multiply_address(int* value);
```

* multiply_value는 정수값을 복사하여 받는다.
* multiply_address는 정수형 변수의 주소를 받는다.

```c
multiply_value(num);
printf("값에 의한 호출 후 num: %d\n", num);
```

* num의 값이 매개변수 value에 복사된다.
* 함수 안에서 value를 변경해도 num은 변경되지 않으므로 입력한 값이 그대로 출력된다.

```c
multiply_address(&num);
printf("주소에 의한 호출 후 num: %d\n", num);
```

* num의 주소를 함수에 전달한다.
* 함수가 주소를 통해 num을 직접 변경하므로 100배 된 값이 출력된다.

```c
void multiply_value(int value)
{
    value *= 100;
}
```

* 복사된 매개변수 value만 100배 한다. 함수가 종료되면 value는 소멸하고 원본 num에는 영향을 주지 않는다.

```c
void multiply_address(int* value)
{
    *value *= 100;
}
```

* 포인터를 간접참조하여 원본 num에 저장된 값을 100배 한다.

## 두 방식의 차이와 원하는 결과

|구분|값에 의한 호출|주소에 의한 호출|
|------|---|---|
|전달하는 것|num의 값|num의 주소|
|매개변수|일반 int형 변수|int형 포인터|
|함수 안에서 변경되는 대상|복사본|원본 num|
|함수 종료 후 num|변경되지 않음|100배로 변경됨|

문제에서 요구하는 것은 num 변수에 저장된 원본 값을 100배 하는 것이므로 주소에 의한 호출 방식이 원하는 결과이다.

# 실행결과

<img width="865" height="92" alt="image" src="https://github.com/user-attachments/assets/77f7cdac-7fad-4f33-97ae-73f7a52e7c19" />
