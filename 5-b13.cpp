/* 2354218 Ð¤¼ÑÍ® ¼Æ¿Æ */
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

#define X_MAX 10
#define Y_MAX 26

int main() {
    srand((unsigned int)(time(0)));  
    char array[X_MAX][Y_MAX] = { 0 };  

    int i = 0;
    while (i < 50) {
        int row = rand() % X_MAX;
        int col = rand() % Y_MAX;
        if (array[row][col] != '*') {
            array[row][col] = '*'; 
            i++;
        }
    }
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
                array[row][col] = count + '0';  
            }
        }
    }

    for (int i = 0; i < X_MAX; i++) {
        for (int j = 0; j < Y_MAX; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl; 
    }

    return 0;
}