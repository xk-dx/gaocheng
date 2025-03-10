/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int top_a = 0;
int top_b = 0;
int top_c = 0;
int stack_a[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stack_b[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stack_c[10] = { 0,0,0,0,0,0,0,0,0,0 };
int num = 1;

void init(int n, char src)
{
    if (src == 'A')
    {
        while (top_a < n)
        {
            stack_a[top_a++] = n - top_a;
        }
    }
    else if (src == 'B')
    {
        while (top_a < n)
        {
            stack_b[top_b++] = n - top_b;
        }
    }
    else if (src == 'C')
    {
        while (top_c < n)
        {
            stack_c[top_c++] = n - top_c;
        }
    }
}

void print()
{
    printf(" A:");
    for (int i = 0; i < 10; i++)
    {
        if (stack_a[i])
            printf("%2d", stack_a[i]);
        else
            printf("  ");
    }
    printf(" B:");
    for (int j = 0; j < 10; j++)
    {
        if (stack_b[j])
            printf("%2d", stack_b[j]);
        else
            printf("  ");
    }
    printf(" C:");
    for (int k = 0; k < 10; k++)
    {
        if (stack_c[k])
            printf("%2d", stack_c[k]);
        else
            printf("  ");
    }
    printf("\n");
}

void push_pop(char src, char dst)
{
    int element = 0;
    if (src == 'A' && top_a > 0)
    {
        element = stack_a[--top_a];
        stack_a[top_a] = 0;
    }
    else if (src == 'B' && top_b > 0)
    {
        element = stack_b[--top_b];
        stack_b[top_b] = 0;
    }
    else if (src == 'C' && top_c > 0)
    {
        element = stack_c[--top_c];
        stack_c[top_c] = 0;
    }
    if (dst == 'A' && top_a < 10)
        stack_a[top_a++] = element;
    else if (dst == 'B' && top_b < 10)
        stack_b[top_b++] = element;
    else if (dst == 'C' && top_c < 10)
        stack_c[top_c++] = element;
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        printf("第%4d 步(%2d): %c-->%c", num++, n, src, dst);
        push_pop(src, dst);
        print();
    }
    else
    {

        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", num++, n, src, dst);
        push_pop(src, dst);
        print();
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n;
    char src, dst, tmp;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        scanf("%d", &n);
        while (getchar() != '\n')
            ;
        if (n >= 1 && n <= 10)
            break;
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &src);
        while (getchar() != '\n')
            ;
        if (src >= 'a' && src <= 'c') {
            src -= 32;
            break;
        }
        if (src >= 'A' && src <= 'C')
            break;
    }

    // 输入目标柱
    while (1) {
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &dst);
        while (getchar() != '\n')
            ;

        if (dst >= 'a' && dst <= 'c') {
            dst -= 32;
        }
        if (dst >= 'A' && dst <= 'C') {
            if (dst == src) {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
            }
            else {
                break;
            }
        }
    }

    if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
        tmp = 'C';
    else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
        tmp = 'B';
    else
        tmp = 'A';
    printf("初始:               ");
    init(n, src);
    print();
    hanoi(n, src, tmp, dst);
    return 0;
}