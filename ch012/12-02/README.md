# 실습과제 1

|수식|결과값|결과값의 자료형|
|------|---|---|
|&ch|100|char* |
|&in|101|int* |
|&db|105|double* |
|*&ch|'A'|char* |
|*&in|10|int* |
|*&db|3.4|double* |

&nbsp;

# 실습과제 2

## 소스코드 설명

```
#include<stdio.h>
```

* printf 등 라이브러리 객체의 선언을 포함하고 있는 헤더파일 stdio.h를 포함하라

```
int main(void)
```

* 메인함수 시작

```
int a = -100;
```

* int형 변수 a의 -100 대입

```
char b = 'A';
```

* char형 변수 b의 'A'라는 문자 대입

```
double c = 3.14;
```

* double형 변수 c의 3.14 대입

```
int* pa = &a;
```

* int형 변수 a의 메모리 주소를 pa라는 포인터 변수에 저장

```
char* pb = &b;
```

* char형 변수 b의 메모리 주소를 pb라는 포인터 변수에 저장

```
double* pc = &c;
```

* double형 변수 c의 메모리 주소를 pc라는 포인터 변수에 저장

```
printf("int형 변수 a의 값은: %d\n", *pa);
printf("char형 변수 b의 값은: %c\n", *pb);
printf("double형 변수 c의 값은: %lf\n", *pc);
```

* printf라는 함수를 이용해서 int형, char형,double형 값을 출력하는 서식 지정자를 통해 포인터가 가리키는 변수의 값을 출력

```
return 0;
```

* 0을 반환하고 메인함수 종료

# 실행결과

<img width="1105" height="178" alt="image" src="https://github.com/user-attachments/assets/ec8307bd-80a4-4566-8f4c-ce5197608260" />

&nsbp;

# 실습과제 3

```
#include<stdio.h>

int main(void)
{
int* ptr= (int*)125; // ①
*ptr= 10;
printf("%d\n", *ptr);
return0;
}
```

* ①에서 ptr은 int* 타입의 포인터 변수이고, 125는 int 타입의 정수이므로 타입이 일치하지 않는다. 따라서 (int*) 강제 형변환을 사용하여 125를 int* 타입으로 변환한 후 ptr에 저장한다.

* 이 코드에서 오류가 나오는 이유는 *ptr = 10을 실행하여 125번지에 값을 저장하려고 하는데, ①에서 ptr를 초기화해주지 않아 쓰레기값이 저장되어 있을 수 있어서 오류가 발생할 수 있다.

&nbsp;

# 실습과제 4

## 소스코드 설명
```
#include<stdio.h>
```

* printf 등 라이브러리 객체의 선언을 포함하고 있는 헤더파일 stdio.h를 포함하라

```
int main(void)
```

* 메인 함수 시작

```
int a = 100, b = 200;
```

* int형 변수 a의 100, b의 200 대입

```
int sum;
```

* int형 변수 sum 생성

```
int* pa = &a;
int* pb = &b;
int* psum = &sum;
```

* int형 변수 a,b,sum의 메모리 주소를 pa,pb,psum라는 포인터 변수에 저장

```
*psum = *pa + *pb;
```

* pa와 pb가 각각 가리키는 값을 더해서, psum이 가리키는 메모리 공간에 저장

```
printf("두정수의 합: %d\n", *psum);
```

* printf 함수를 이용해서 포인터가 가리키는 변수의 값을 출력

```
return 0;
```

* 0을 반환하고 메인함수 종료

&nsbp;

# 실습과제 5

## 문제

정수형 변수 num1과 num2를 선언하여 각각 25와 40으로 초기화하고, 포인터 변수 ptr1과 ptr2가 각각 num1과 num2를 가리키도록 하시오.
두 포인터가 가리키는 값을 비교하여, 더 작은 값에는 10을 더하고 더 큰 값에는 10을 빼시오.
그 후 두 포인터가 가리키는 값을 서로 교환한 뒤 변경된 num1과 num2의 값을 각각 출력하는 프로그램을 작성하시오.

