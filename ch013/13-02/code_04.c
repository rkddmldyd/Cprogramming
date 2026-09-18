// **********************************************
// 제 목 : 사전에서 가장 앞에 나오는 문자열 찾기
// 날 짜 : 2026년 9월 18일
// 작성자 : 2600172 정준석
// **********************************************

#include <stdio.h>

int main(void)
{
    const char* fruits[] = { "apple", "blueberry", "orange", "melon" };
    int i;
    int min = 0;
    int count = sizeof(fruits) / sizeof(fruits[0]);

    for (i = 1; i < count; i++)
    {
        if (fruits[i][0] < fruits[min][0])
            min = i;
    }

    printf("사전에서 가장 앞에 나오는 문자열: %s\n", fruits[min]);

    return 0;
}
