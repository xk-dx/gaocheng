/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdbool.h>

int main() {
    double a;
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &a);

    int sy = (int)(a / 1000000000) % 10;
    int yi = (int)(a / 100000000) % 10;
    int qw = (int)(a / 10000000) % 10;
    int bw = (int)(a / 1000000) % 10;
    int sw = (int)(a / 100000) % 10;
    int w = (int)(a / 10000) % 10;
    int q = (int)(a / 1000) % 10;
    int b = (int)(a / 100) % 10;
    a /= 100;
    a -= (int)a;
    a *= 10000;
    a += 0.001;
    int s = (int)(a / 1000) % 10;
    int y = (int)(a / 100) % 10;
    int j = (int)(a / 10) % 10;
    int f = (int)a % 10;
    printf("��д�����:\n");
    //ʮ��
    if (sy == 1) {
        printf("Ҽʰ");
    }
    else if (sy == 2) {
        printf("��ʰ");
    }
    else if (sy == 3) {
        printf("��ʰ");
    }
    else if (sy == 4) {
        printf("��ʰ");
    }
    else if (sy == 5) {
        printf("��ʰ");
    }
    else if (sy == 6) {
        printf("½ʰ");
    }
    else if (sy == 7) {
        printf("��ʰ");
    }
    else if (sy == 8) {
        printf("��ʰ");
    }
    else if (sy == 9) {
        printf("��ʰ");
    }

    //��
    if (yi == 1) {
        printf("Ҽ");
    }
    else if (yi == 2) {
        printf("��");
    }
    else if (yi == 3) {
        printf("��");
    }
    else if (yi == 4) {
        printf("��");
    }
    else if (yi == 5) {
        printf("��");
    }
    else if (yi == 6) {
        printf("½");
    }
    else if (yi == 7) {
        printf("��");
    }
    else if (yi == 8) {
        printf("��");
    }
    else if (yi == 9) {
        printf("��");
    }
    if (sy != 0 || yi != 0)
        printf("��");

    //ǧ��
    if (qw == 1) {
        printf("ҼǪ");
    }
    else if (qw == 2) {
        printf("��Ǫ");
    }
    else if (qw == 3) {
        printf("��Ǫ");
    }
    else if (qw == 4) {
        printf("��Ǫ");
    }
    else if (qw == 5) {
        printf("��Ǫ");
    }
    else if (qw == 6) {
        printf("½Ǫ");
    }
    else if (qw == 7) {
        printf("��Ǫ");
    }
    else if (qw == 8) {
        printf("��Ǫ");
    }
    else if (qw == 9) {
        printf("��Ǫ");
    }
    else if (qw == 0 && (sy != 0 || yi != 0) && (sw != 0 || bw != 0 || w != 0)) {
        printf("��");
    }

    //����
    if (bw == 1) {
        printf("Ҽ��");
    }
    else if (bw == 2) {
        printf("����");
    }
    else if (bw == 3) {
        printf("����");
    }
    else if (bw == 4) {
        printf("����");
    }
    else if (bw == 5) {
        printf("���");
    }
    else if (bw == 6) {
        printf("½��");
    }
    else if (bw == 7) {
        printf("���");
    }
    else if (bw == 8) {
        printf("�ư�");
    }
    else if (bw == 9) {
        printf("����");
    }
    else if (qw != 0 && bw == 0 && (sw != 0 || w != 0)) {
        printf("��");
    }

    //ʮ��
    if (sw == 1) {
        printf("Ҽʰ");
    }
    else if (sw == 2) {
        printf("��ʰ");
    }
    else if (sw == 3) {
        printf("��ʰ");
    }
    else if (sw == 4) {
        printf("��ʰ");
    }
    else if (sw == 5) {
        printf("��ʰ");
    }
    else if (sw == 6) {
        printf("½ʰ");
    }
    else if (sw == 7) {
        printf("��ʰ");
    }
    else if (sw == 8) {
        printf("��ʰ");
    }
    else if (sw == 9) {
        printf("��ʰ");
    }
    else if (bw != 0 && sw == 0 && w != 0) {
        printf("��");
    }

    // �жϲ�ת����λ
    if (w == 1) {
        printf("Ҽ");
    }
    else if (w == 2) {
        printf("��");
    }
    else if (w == 3) {
        printf("��");
    }
    else if (w == 4) {
        printf("��");
    }
    else if (w == 5) {
        printf("��");
    }
    else if (w == 6) {
        printf("½");
    }
    else if (w == 7) {
        printf("��");
    }
    else if (w == 8) {
        printf("��");
    }
    else if (w == 9) {
        printf("��");
    }
    if (sw != 0 || bw != 0 || qw != 0 || w != 0)
        printf("��");

    //ǧ��
    if (q == 1) {
        printf("ҼǪ");
    }
    else if (q == 2) {
        printf("��Ǫ");
    }
    else if (q == 3) {
        printf("��Ǫ");
    }
    else if (q == 4) {
        printf("��Ǫ");
    }
    else if (q == 5) {
        printf("��Ǫ");
    }
    else if (q == 6) {
        printf("½Ǫ");
    }
    else if (q == 7) {
        printf("��Ǫ");
    }
    else if (q == 8) {
        printf("��Ǫ");
    }
    else if (q == 9) {
        printf("��Ǫ");
    }
    else if (q == 0 && (sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0) && (b != 0 || s != 0 || y != 0)) {
        printf("��");
    }

    //��
    if (b == 1) {
        printf("Ҽ��");
    }
    else if (b == 2) {
        printf("����");
    }
    else if (b == 3) {
        printf("����");
    }
    else if (b == 4) {
        printf("����");
    }
    else if (b == 5) {
        printf("���");
    }
    else if (b == 6) {
        printf("½��");
    }
    else if (b == 7) {
        printf("���");
    }
    else if (b == 8) {
        printf("�ư�");
    }
    else if (b == 9) {
        printf("����");
    }
    else if (q != 0 && b == 0 && (s != 0 || y != 0)) {
        printf("��");
    }

    //ʮ
    if (s == 1) {
        printf("Ҽʰ");
    }
    else if (s == 2) {
        printf("��ʰ");
    }
    else if (s == 3) {
        printf("��ʰ");
    }
    else if (s == 4) {
        printf("��ʰ");
    }
    else if (s == 5) {
        printf("��ʰ");
    }
    else if (s == 6) {
        printf("½ʰ");
    }
    else if (s == 7) {
        printf("��ʰ");
    }
    else if (s == 8) {
        printf("��ʰ");
    }
    else if (s == 9) {
        printf("��ʰ");
    }
    else if (b != 0 && s == 0 && y != 0) {
        printf("��");
    }

    //��λ
    if (y == 1) {
        printf("Ҽ");
    }
    else if (y == 2) {
        printf("��");
    }
    else if (y == 3) {
        printf("��");
    }
    else if (y == 4) {
        printf("��");
    }
    else if (y == 5) {
        printf("��");
    }
    else if (y == 6) {
        printf("½");
    }
    else if (y == 7) {
        printf("��");
    }
    else if (y == 8) {
        printf("��");
    }
    else if (y == 9) {
        printf("��");
    }

    int is_z=0;//������Ϊ0
    if (sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || y != 0) {
        is_z = 1;
        printf("Բ");
    }
    //��
    if (j == 1) {
        printf("Ҽ��");
    }
    else if (j == 2) {
        printf("����");
    }
    else if (j == 3) {
        printf("����");
    }
    else if (j == 4) {
        printf("����");
    }
    else if (j == 5) {
        printf("���");
    }
    else if (j == 6) {
        printf("½��");
    }
    else if (j == 7) {
        printf("���");
    }
    else if (j == 8) {
        printf("�ƽ�");
    }
    else if (j == 9) {
        printf("����");
    }
    else if (j == 0 && f != 0 && is_z==1) {
        printf("��") ;
    }
    else if (j == 0 && f == 0 && is_z==1) {
        printf("��") ;
    }
    else if (j == 0 && f == 0 && is_z==0) {
        printf("��Բ��") ;
    }
    //��
    if (f == 1) {
        printf("Ҽ��");
    }
    else if (f == 2) {
        printf("����");
    }
    else if (f == 3) {
        printf("����");
    }
    else if (f == 4) {
        printf("����");
    }
    else if (f == 5) {
        printf("���");
    }
    else if (f == 6) {
        printf("½��");
    }
    else if (f == 7) {
        printf("���");
    }
    else if (f == 8) {
        printf("�Ʒ�");
    }
    else if (f == 9) {
        printf("����");
    }
    else if (f == 0 && j != 0) {
        printf("��");
    }
    printf("\n");
    return 0;
}
