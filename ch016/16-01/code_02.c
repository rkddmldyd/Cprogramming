// **********************************************
// 제 목 : 세 학생의 평균과 최우수 학생 구하기
// 날 짜 : 2026년 10월 2일
// 작성자 : 2600172 정준석
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int score[3][3];
    double average[3];
    int i, j, total, best = 0;

    // 각 행은 학생, 각 열은 국어, 영어, 수학 점수
    for (i = 0; i < 3; i++)
    {
        printf("%d번째 학생의 국어,영어,수학 성적을 입력: ", i + 1);
        total = 0;
        for (j = 0; j < 3; j++)
        {
            if (scanf("%d", &score[i][j]) != 1)
                return 1;
            if (score[i][j] < 0 || score[i][j] > 100)
            {
                printf("성적은 0부터 100 사이의 정수를 입력하시오.\n");
                return 1;
            }
            total += score[i][j];
        }
        average[i] = total / 3.0;
    }

    // 평균이 같은 경우 먼저 입력한 학생을 선택
    for (i = 1; i < 3; i++)
        if (average[i] > average[best])
            best = i;

    printf("최우수 학생은 %d번째 학생이고 평균점수는 %g점이다.\n",
        best + 1, average[best]);
    return 0;
}
