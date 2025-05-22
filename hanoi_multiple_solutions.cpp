/* �ƿ� 2354218 Ф��ͮ */
#include "hanoi.h"
using namespace std;
int stack_a[10] = { 0 };
int stack_b[10] = { 0 };
int stack_c[10] = { 0 };
int top_a = 0;
int top_b = 0;
int top_c = 0;
static int num = 1;
static int speed;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
/***************************************************************************
     �������ƣ��������ͣ
     ��    �ܣ�
     ���������
     �� �� ֵ��
     ˵    ����
/***************************************************************************/
void cult()
{
   // cct_gotoxy(x, y);
    cout << "���س�������";
    while (_getch() != '\r')
        ;
}
/***************************************************************************
  �������ƣ�void reset()
  ��    �ܣ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void reset()
{
    num = 1;
    top_a = 0;
    top_b = 0;
    top_c = 0;
    for (int i = 0; i < 10; i++) {
        stack_a[i] = 0;
        stack_b[i] = 0;
        stack_c[i] = 0;
    }
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/***************************************************************************
  �������ƣ�void time_sleep(��
  ��    �ܣ�ʱ����ͣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void time_sleep() {
    int Time;
    switch (speed)
    {
        case(1):
            Time = 200;
            break;
        case(2):
            Time = 100;
            break;
        case(3):
            Time = 50;
            break;
        case(4):
            Time = 20;
            break;
        case(5):
            Time = 0;
            break;
    }
    if (speed)
    {
        Sleep(Time);
    }
    else
    {
        while (_getch() != '\r')
            ;
    }
}
/***************************************************************************
  �������ƣ�void init(int n, char src)
  ��    �ܣ���ʼ����ʼ��
  �����������������ʼ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
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
/***************************************************************************
  �������ƣ�void print_w()
  ��    �ܣ������ӡ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_w()
{
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if (stack_a[i])
            cout << setw(2) << stack_a[i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (stack_b[i])
            cout << setw(2) << stack_b[i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (stack_c[i])
            cout << setw(2) << stack_c[i];
        else
            cout << "  ";
    }
    cout << endl;
}
/***************************************************************************
  �������ƣ�void print_v_init(char src, char dst, int speed)
  ��    �ܣ������ʼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_v_init(char src, char dst, int speed,int x,int y)
{
    cct_gotoxy(0, y);
    cout << "         =========================" << endl;
    cout << "           A         B         C";
    for (int i = 0; i < top_a; i++)
    {
        cct_gotoxy(x, y -1 - i);
        if (stack_a[i])
        {
            cout << setw(2) << stack_a[i];
        }
    }
    for (int i = 0; i < top_b; i++)
    {
        cct_gotoxy(x+10, y-1- i);
        if (stack_b[i])
        {
            cout << setw(2) << stack_b[i];
        }
    }
    for (int i = 0; i < top_c; i++)
    {
        cct_gotoxy(x+20, y - 1 - i);
        if (stack_c[i])
        {
            cout << setw(2) << stack_c[i];
        }
    }
}
    
/***************************************************************************
�������ƣ�void print_v_init(char src, char dst, int speed)
��    �ܣ������ӡ
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void print_v(char src, char dst, int speed,int x,int y)
{
    if (src == 'A')
    {
        cct_gotoxy(x, y-1 - top_a);
        cout << "  ";
    }
    else if (src == 'B')
    {
        cct_gotoxy(x+10, y-1 - top_b);
        cout << "  ";
    }
    else if (src == 'C')
    {
        cct_gotoxy(x+20, y-1 - top_c);
        cout << "  ";
    }
    if (dst == 'A')
    {
        cct_gotoxy(x, y - top_a);
        cout << setw(2) << stack_a[top_a - 1];
    }
    else if (dst == 'B')
    {
        cct_gotoxy(x+10, y - top_b);
        cout << setw(2) << stack_b[top_b - 1];
    }
    else if (dst == 'C')
    {
        cct_gotoxy(x+20, y - top_c);
        cout << setw(2) << stack_c[top_c - 1];
    }
}
/***************************************************************************
�������ƣ� void push_pop(char src, char dst)
��    �ܣ� �ƶ���ջ
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void push_pop(char src, char dst)
{
    int ele = 0;
    if (src == 'A' && top_a > 0)
    {
        ele = stack_a[--top_a];
        stack_a[top_a] = 0;
    }
    else if (src == 'B' && top_b > 0)
    {
        ele = stack_b[--top_b];
        stack_b[top_b] = 0;
    }
    else if (src == 'C' && top_c > 0)
    {
        ele = stack_c[--top_c];
        stack_c[top_c] = 0;
    }
    if (dst == 'A' && top_a < 10) {
        stack_a[top_a] = ele;
        top_a++;
    }
    else if (dst == 'B' && top_b < 10) {
        stack_b[top_b] = ele;
        top_b++;
    }
    else if (dst == 'C' && top_c < 10) {
        stack_c[top_c] = ele;
        top_c++;
    }
}

/***************************************************************************
�������ƣ� Input
��    �ܣ� ����
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void Input_h(char* src, char* tmp, char* dst, int* n,int if_speed)
{
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> *n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (*n >= 1 && *n <= 10)
            break;
    }

    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> *src;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*src >= 'a' && *src <= 'c') {
            *src -= 32;
            break;
        }
        if (*src >= 'A' && *src <= 'C')
            break;
    }
    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> *dst;
        cin.clear();
        cin.ignore(65536, '\n');

        if (*dst >= 'a' && *dst <= 'c') {
            *dst -= 32;
        }
        if (*dst >= 'A' && *dst <= 'C')
            if (*dst == *src)
                cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
            else
                break;
    }
    if ((*src == 'A' && *dst == 'B') || (*src == 'B' && *dst == 'A'))
        *tmp = 'C';
    else if ((*src == 'A' && *dst == 'C') || (*src == 'C' && *dst == 'A'))
        *tmp = 'B';
    else
        *tmp = 'A';
    if (if_speed) {
        while (1)
        {
            cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-5:��ʱ��ӦΪ200ms/100ms/50ms/20ms/0ms)" << endl;
            cin >> speed;
            cin.clear();
            cin.ignore(65536, '\n');
            if (speed >= 0 && speed <= 5)
                break;
        }
    }
}

/***************************************************************************
�������ƣ�print_cols
��    �ܣ�����������
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void print_cols()
{
    cct_setcursor(CURSOR_INVISIBLE);
    cct_showch(1, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 23);
    cct_showch(33, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 23);
    cct_showch(33+32, 15, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 23);
    for (int i = 0; i < col_h; i++)
    {
        cct_showch(a_middle, base_y - 1 - i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        Sleep(30);
        cct_showch(b_middle, base_y - 1 - i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        Sleep(30);
        cct_showch(c_middle, base_y - 1 - i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        Sleep(30);
    }
}
/***************************************************************************
�������ƣ�print_plate_init(int n,char src)
��    �ܣ����ӳ�ʼ��
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void print_plate_init(int n,char src)
{
    char base;
    if (src=='A')
        base=  a_middle;
    else if (src == 'B')
        base = b_middle;
    else if (src == 'C')
        base = c_middle;
    for (int i = 0; i <n; i++)
    {
        cct_showch(base - n + i, base_y - 1 - i, ' ', n-i, n-i, 2 * (n-i) + 1);
        Sleep(50);
    }


}
/***************************************************************************
�������ƣ����ֲ���
��    �ܣ�op
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void op(char src, char tmp, char dst, int n, int choice)
{
    if (choice == 1)
        cout << n << "# " << src << "---->" << dst << endl;
    else if (choice == 2)
    {
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
    }
    else if (choice == 3)
    {
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        push_pop(src, dst);
        print_w();
    }
    else if (choice == 4)
    {
        cct_gotoxy(0, 17);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        push_pop(src, dst);
        print_w();
        print_v(src, dst, speed,10,12);
        time_sleep();
    }
    else if (choice == 7)
        move_plate(src, dst);
    else if (choice == 8) {
        cct_gotoxy(0, 32);    
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        push_pop(src, dst);
        cct_gotoxy(21, 32);
        print_w();
        print_v(src, dst, speed,10,27);
        push_pop(dst, src);
        move_plate(src, dst);
        push_pop(src, dst);
        time_sleep();
    }
}
/***************************************************************************
�������ƣ�void move_plate(char src, char dst)
��    �ܣ��ƶ�plate
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void move_plate(char src, char dst)
{
    int Time;
    switch (speed)
    {
        case(0):
            Time = 50;
            break;
        case(1):
            Time = 200;
            break;
        case(2):
            Time = 100;
            break;
        case(3):
            Time = 50;
            break;
        case(4):
            Time = 20;
            break;
        case(5):
            Time = 0;
            break;
    }
    int st_x,st_y,ele,dst_x,end_y;
    if (src == 'A') {
        st_x = a_middle;
        st_y = base_y - top_a;
        ele = stack_a[top_a - 1];
    }
    else if (src == 'B') {
        st_x = b_middle;
        st_y = base_y - top_b;
        ele = stack_b[top_b - 1];
    }
    else if (src == 'C') {
        st_x = c_middle;
        st_y = base_y - top_c;
        ele = stack_c[top_c - 1];
    }
    if (dst == 'A') {
        dst_x = a_middle;
        end_y = base_y - top_a-1;
    }
    else if (dst == 'B') {
        dst_x = b_middle;
        end_y = base_y - top_b - 1;
    }
    else if (dst == 'C') {
        dst_x = c_middle;
        end_y = base_y - top_c - 1;
    }

    for (int i = st_y; i >= 1; i--) {
        cct_showch(st_x - ele, i, ' ', ele, ele, 2 * ele + 1);
        Sleep(Time);
        cct_showch(st_x - ele, i, ' ', COLOR_BLACK, COLOR_BLACK, 2 * ele + 1);
        if (i > 2)
            cct_showch(st_x, i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
    }
    //Move_Crosswise
    if (src < dst)
    {
        for (int i = st_x - ele; i <= dst_x - ele; i++)
        {
            cct_showch(i, 1, ' ', ele, ele, 2 * ele + 1);
            Sleep(Time);
            cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_BLACK, 2 * ele + 1);
        }
    }
    else
    {
        for (int i = st_x - ele; i >= dst_x -ele ; i--)
        {
            cct_showch(i, 1, ' ', ele, ele, 2 * ele + 1);
            Sleep(Time);
            cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_BLACK, 2 * ele + 1);
        }
    }
    //Move_Vertical_Down;
    for (int i = 1; i <= end_y; i++)
    {
        cct_showch(dst_x-ele, i, ' ',ele , ele, 2 * ele + 1);
        Sleep(Time);
        if (i < end_y)
        {
            cct_showch(dst_x - ele , i, ' ', COLOR_BLACK, COLOR_BLACK, 2 * ele + 1);
            if (i > 2)
                cct_showch(dst_x, i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/***************************************************************************
�������ƣ�hanoi
��    �ܣ��ݹ麯��
���������
�� �� ֵ��
˵    ����
***************************************************************************/
void hanoi(char src, char tmp, char dst, int n, int choice)
{
    if (n == 1)
        op(src, tmp, dst, n,  choice);
    else
    {
        hanoi(src, dst, tmp, n - 1,  choice);
        if (choice == 7)
            return;
        op(src, tmp, dst, n, choice);
        hanoi(tmp, src, dst, n - 1, choice);
    }
}


void choice_1()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 0);
    hanoi(src, tmp, dst, n, 1);
    cout << endl;
    cult();
}

void choice_2()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 0);
    hanoi(src, tmp, dst, n, 2);
    cout << endl;
    num = 1;
    cult();
}

void choice_3()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 0);
    init(n,src);
    hanoi(src, tmp, dst, n, 3);
    cout << endl;
    reset();
    cult();
}

void choice_4()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 1);
    init(n, src);
    cct_setcursor(CURSOR_INVISIBLE);
    cct_cls();
    cct_gotoxy(0, 0);
    cout << "�� " << src << " �ƶ��� " << dst << " ,�� " << "n" << " ��, ��ʱ����Ϊ " << speed;
    cct_gotoxy(0, 17);
    cout << "��ʼ: ";
    print_w();
    print_v_init(src, dst, speed,10,12);
    time_sleep();
    hanoi(src, tmp, dst, n, 4);
    reset();
    cct_gotoxy(0, 38);
    cult();
}

void choice_5()
{
    cct_cls();
    print_cols();
    cct_gotoxy(0, 38);
    reset();
    cult();
}

void choice_6()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 0);
    init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
    print_cols();
    print_plate_init(n, src);
    cct_gotoxy(0, 38);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    reset();
    cult();
}

void choice_7()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 0);
    init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
    print_cols();
    print_plate_init(n, src);
    Sleep(100);
    hanoi(src, tmp, dst, n,7);
    cct_gotoxy(0, 38);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    reset();
    cult();
}
void choice_8()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 1);
    init(n, src);
    cct_setcursor(CURSOR_INVISIBLE);
    cct_cls();
    //
    cct_gotoxy(0, 0);
    cout << "�� " << src << " �ƶ��� " << dst << " ,�� " << n << " ��, ��ʱ����Ϊ " << speed;
    cct_gotoxy(0, 32);
    cout << "��ʼ: ";
    cct_gotoxy(5, 32);
    print_w();
    print_v_init(src, dst, speed, 10, 27);
    print_cols();
    print_plate_init(n, src);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    time_sleep();
    hanoi(src, tmp, dst, n, 8);
    reset();
    cct_gotoxy(0, 38);
    cult();
}
void choice_9()
{
    char src, tmp, dst;
    int n;
    Input_h(&src, &tmp, &dst, &n, 0);
    cct_cls();
    init(n, src);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
    cct_gotoxy(0, 32);
    cout << "��ʼ:  ";
    print_w();
    print_v_init(src, dst, speed, 10, 27);
    print_cols();
    print_plate_init(n, src);
    //����
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);

    cct_gotoxy(0, 34);
    cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
    char i_src, i_dst;
    while (true)
    {
        while (1)
        {
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            int out, in = 1000, flag = 1;
            cct_showch(60, 34, ' ', COLOR_BLACK, COLOR_WHITE, 10);
            cct_showch(0, 35, ' ', COLOR_BLACK, COLOR_WHITE, 30);
            cct_gotoxy(60, 34);
            i_src = getchar();
            if (i_src == '\n')
                continue;
            if (i_src == 'Q' || i_src == 'q')
            {
                cout << "��Ϸ��ֹ!!!!!" << endl;
                cct_gotoxy(0, 38);
                reset();
                cult();
                return;
            }
            i_dst = getchar();
            cin.clear();
            cin.ignore(65536, '\n');
           
            if (i_src >= 'a' && i_src <= 'c')
                i_src -= 32;
            if (i_dst >= 'a' && i_dst <= 'c')
                i_dst -= 32;
            if (i_dst >= 'A' && i_dst <= 'C' && i_src >= 'A' && i_src <= 'C'&&i_src!=i_dst) {
                if (i_src == 'A') {
                    if (top_a > 0)
                        out = stack_a[top_a - 1];
                    else
                        flag = 0;
                }
                else if (i_src == 'B') {
                    if (top_b > 0)
                        out = stack_b[top_b - 1];
                    else
                        flag = 0;
                }
                else if (i_src == 'C') {
                    if (top_c > 0)
                        out = stack_c[top_c - 1];
                    else
                        flag = 0;
                }

                if (i_dst == 'A' && top_a > 0)
                    in = stack_a[top_a - 1];
                else if (i_dst == 'B' && top_b > 0)
                    in = stack_b[top_b - 1];
                else if (i_dst == 'C' && top_c > 0)
                    in = stack_c[top_c - 1];
                if (!flag) {
                    cct_gotoxy(0, 35);
                    cout << "��ԴΪ�գ�";
                    Sleep(1000);
                    cct_showch(0, 35, ' ', COLOR_BLACK, COLOR_WHITE, 10);
                    continue;
                }
                else if (in < out) {
                    cct_gotoxy(0, 35);
                    cout << "����ѹС�̣��Ƿ��ƶ�!";
                    Sleep(1000);
                    cct_showch(0, 35, ' ', COLOR_BLACK, COLOR_WHITE, 10);
                    continue;
                }
                break;
            }
        }
        //����
        speed = 4;
        cct_gotoxy(0, 32);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        push_pop(i_src, i_dst);
        cct_gotoxy(21, 32);
        print_w();
        print_v(i_src, i_dst, speed, 10, 27);
        push_pop(i_dst, i_src);
        move_plate(i_src, i_dst);
        push_pop(i_src, i_dst);
        cct_showch(60, 34, ' ', COLOR_BLACK, COLOR_WHITE, 10);
        int f;
        if (dst == 'A')
            f = stack_a[n - 1];
        else if (dst == 'B')
            f = stack_b[n - 1];
        else if (dst == 'C')
            f = stack_c[n - 1];
       //�жϽ���
        if (f == 1)
        {
            cct_showstr(0, 35, "��Ϸ����!!!!!", COLOR_BLACK, COLOR_WHITE, 1);
            cct_gotoxy(0, 38);
            reset();
            cult();
            break;
        }
    }
}