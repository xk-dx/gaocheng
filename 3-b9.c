/* 2354218 Ð¤¼ÑÍ® ¼Æ¿Æ */
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>

int main()
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%dx%d=%-2d", j, i, j * i);
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

 