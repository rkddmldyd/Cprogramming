# 소스코드 설명

```
#include <stdio.h>
```

* printf 등 라이브러리 객체의 선언을 포함하고 있는 헤더파일 stdio.h를 포함하라

```
int main(void)
```

* 메인함수 시작

```
char a = 'A';
```

* char형 변수 a의 'A'라는 문자 대입

```
int b = 36;
```

* int형 변수 b의 36 대입

```
double c = 3.141592;
```

* double형 변수 c의 3.141592 대입

```
printf("char형 변수 a의 주소: %u \n", &a);
printf("int형 변수 b의 주소: %u \n", &b);
printf("double형 변수 c의 주소 : %u \n", &c);
```

* printf 함수를 이용하여 변수 a,b,c의 주소 출력, %u는 부호없는 정수를 출력하는 서식 문자이고 &a, %b, %c의 %(앰퍼센드)는 변수의 주소를 계산하는 연산자임

```
return 0;
```

* 0을 반환하고 메인함수 정상 종료

# 실행결과

<img width="1101" height="174" alt="image" src="https://github.com/user-attachments/assets/e34388d7-8833-4044-90a8-8c60f3750fb7" />
