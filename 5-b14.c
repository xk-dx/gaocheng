/* 2354218 Ф��ͮ �ƿ� */
/*2250778 �����  2353328 ���� 2350797 κԴ�� 2353882 ������ 2351017 ����[*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define X_MAX 10
#define Y_MAX 26

int main()
{
    char array[X_MAX][Y_MAX];
    for (int i = 0; i < X_MAX; i++) {
        int j = 0;
        while (j< Y_MAX){
            scanf("%c", &array[i][j]);
            if (array[i][j] != ' ' && array[i][j] != '\n')
                j++;
        }
     }
    int count = 0;

        for (int i = 0; i < X_MAX; i++)
        {
            for (int j = 0; j < Y_MAX; j++)
            {
                if (array[i][j] == '*')
                    count++;
            }
        }
        if (count != 50)
        {
            printf("����1\n");
            return 0;
        }

        int ret = 1;
        //����2
        for (int row = 0; row < X_MAX; row++) {
            for (int col = 0; col < Y_MAX; col++) {
                if (array[row][col] != '*') {
                    int count = 0;
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            if (i == 0 && j == 0)
                                continue;
                            int newrow = row + i;
                            int newcol = col + j;
                            if (newrow >= 0 && newrow < X_MAX && newcol >= 0 && newcol < Y_MAX) {
                                if (array[newrow][newcol] == '*') {
                                    count++;
                                }
                            }
                        }
                    }
                    if (array[row][col] != '0' + count) {
                        printf("����2\n");
                        return 0;
                    }
                }
            }
        }
        printf("��ȷ\n");
        return 0;
}