/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void input(char id[][8], char name[][9], int score[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%s %s %d", id[i], name[i], &score[i]);
    }
    printf("\n");
}


void sort(char id[][8], char name[][9], int score[])
{
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (strcmp(id[i], id[j]) < 0) {
                char tempid[8];
                strcpy(tempid, id[i]);
                strcpy(id[i], id[j]);
                strcpy(id[j], tempid);
                char tempname[9];
                strcpy(tempname, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tempname);
                int tempScore = score[i];
                score[i] = score[j];
                score[j] = tempScore;
            }
        }
    }
}

void output(char id[][8], char name[][9], int score[])
{
    printf("及格名单(学号降序):\n");
    for (int i = 0; i < 10; i++) {
        if (score[i] >= 60) {
            printf("%s %s %d\n", name[i], id[i], score[i]);
        }
    }

}


int main()
{
	char id[10][8];
	char name[10][9];
	int score[10] = { 0 };

    input(id, name, score);
    sort(id, name, score);
    output(id, name, score);

    return 0;
}