/* 2354218 肖佳彤 计科 */
/*2250778 仇鹏皓  2353328 刘盼 2350797 魏源哲 2353882 车国昱 2351017 宁雨璠*/
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
            printf("错误1\n");
            return 0;
        }

        int ret = 1;
        //错误2
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
                        printf("错误2\n");
                        return 0;
                    }
                }
            }
        }
        printf("正确\n");
        return 0;
}