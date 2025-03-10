/* 2354218 Ð¤¼ÑÍ® ¼Æ¿Æ */
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdbool.h>

int main() {
    double a;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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
    printf("´óÐ´½á¹ûÊÇ:\n");
    //Ê®ÒÚ
    if (sy == 1) {
        printf("Ò¼Ê°");
    }
    else if (sy == 2) {
        printf("·¡Ê°");
    }
    else if (sy == 3) {
        printf("ÈþÊ°");
    }
    else if (sy == 4) {
        printf("ËÁÊ°");
    }
    else if (sy == 5) {
        printf("ÎéÊ°");
    }
    else if (sy == 6) {
        printf("Â½Ê°");
    }
    else if (sy == 7) {
        printf("ÆâÊ°");
    }
    else if (sy == 8) {
        printf("°ÆÊ°");
    }
    else if (sy == 9) {
        printf("¾ÁÊ°");
    }

    //ÒÚ
    if (yi == 1) {
        printf("Ò¼");
    }
    else if (yi == 2) {
        printf("·¡");
    }
    else if (yi == 3) {
        printf("Èþ");
    }
    else if (yi == 4) {
        printf("ËÁ");
    }
    else if (yi == 5) {
        printf("Îé");
    }
    else if (yi == 6) {
        printf("Â½");
    }
    else if (yi == 7) {
        printf("Æâ");
    }
    else if (yi == 8) {
        printf("°Æ");
    }
    else if (yi == 9) {
        printf("¾Á");
    }
    if (sy != 0 || yi != 0)
        printf("ÒÚ");

    //Ç§Íò
    if (qw == 1) {
        printf("Ò¼Çª");
    }
    else if (qw == 2) {
        printf("·¡Çª");
    }
    else if (qw == 3) {
        printf("ÈþÇª");
    }
    else if (qw == 4) {
        printf("ËÁÇª");
    }
    else if (qw == 5) {
        printf("ÎéÇª");
    }
    else if (qw == 6) {
        printf("Â½Çª");
    }
    else if (qw == 7) {
        printf("ÆâÇª");
    }
    else if (qw == 8) {
        printf("°ÆÇª");
    }
    else if (qw == 9) {
        printf("¾ÁÇª");
    }
    else if (qw == 0 && (sy != 0 || yi != 0) && (sw != 0 || bw != 0 || w != 0)) {
        printf("Áã");
    }

    //°ÙÍò
    if (bw == 1) {
        printf("Ò¼°Û");
    }
    else if (bw == 2) {
        printf("·¡°Û");
    }
    else if (bw == 3) {
        printf("Èþ°Û");
    }
    else if (bw == 4) {
        printf("ËÁ°Û");
    }
    else if (bw == 5) {
        printf("Îé°Û");
    }
    else if (bw == 6) {
        printf("Â½°Û");
    }
    else if (bw == 7) {
        printf("Æâ°Û");
    }
    else if (bw == 8) {
        printf("°Æ°Û");
    }
    else if (bw == 9) {
        printf("¾Á°Û");
    }
    else if (qw != 0 && bw == 0 && (sw != 0 || w != 0)) {
        printf("Áã");
    }

    //Ê®Íò
    if (sw == 1) {
        printf("Ò¼Ê°");
    }
    else if (sw == 2) {
        printf("·¡Ê°");
    }
    else if (sw == 3) {
        printf("ÈþÊ°");
    }
    else if (sw == 4) {
        printf("ËÁÊ°");
    }
    else if (sw == 5) {
        printf("ÎéÊ°");
    }
    else if (sw == 6) {
        printf("Â½Ê°");
    }
    else if (sw == 7) {
        printf("ÆâÊ°");
    }
    else if (sw == 8) {
        printf("°ÆÊ°");
    }
    else if (sw == 9) {
        printf("¾ÁÊ°");
    }
    else if (bw != 0 && sw == 0 && w != 0) {
        printf("Áã");
    }

    // ÅÐ¶Ï²¢×ª»»ÍòÎ»
    if (w == 1) {
        printf("Ò¼");
    }
    else if (w == 2) {
        printf("·¡");
    }
    else if (w == 3) {
        printf("Èþ");
    }
    else if (w == 4) {
        printf("ËÁ");
    }
    else if (w == 5) {
        printf("Îé");
    }
    else if (w == 6) {
        printf("Â½");
    }
    else if (w == 7) {
        printf("Æâ");
    }
    else if (w == 8) {
        printf("°Æ");
    }
    else if (w == 9) {
        printf("¾Á");
    }
    if (sw != 0 || bw != 0 || qw != 0 || w != 0)
        printf("Íò");

    //Ç§Íò
    if (q == 1) {
        printf("Ò¼Çª");
    }
    else if (q == 2) {
        printf("·¡Çª");
    }
    else if (q == 3) {
        printf("ÈþÇª");
    }
    else if (q == 4) {
        printf("ËÁÇª");
    }
    else if (q == 5) {
        printf("ÎéÇª");
    }
    else if (q == 6) {
        printf("Â½Çª");
    }
    else if (q == 7) {
        printf("ÆâÇª");
    }
    else if (q == 8) {
        printf("°ÆÇª");
    }
    else if (q == 9) {
        printf("¾ÁÇª");
    }
    else if (q == 0 && (sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0) && (b != 0 || s != 0 || y != 0)) {
        printf("Áã");
    }

    //°Ù
    if (b == 1) {
        printf("Ò¼°Û");
    }
    else if (b == 2) {
        printf("·¡°Û");
    }
    else if (b == 3) {
        printf("Èþ°Û");
    }
    else if (b == 4) {
        printf("ËÁ°Û");
    }
    else if (b == 5) {
        printf("Îé°Û");
    }
    else if (b == 6) {
        printf("Â½°Û");
    }
    else if (b == 7) {
        printf("Æâ°Û");
    }
    else if (b == 8) {
        printf("°Æ°Û");
    }
    else if (b == 9) {
        printf("¾Á°Û");
    }
    else if (q != 0 && b == 0 && (s != 0 || y != 0)) {
        printf("Áã");
    }

    //Ê®
    if (s == 1) {
        printf("Ò¼Ê°");
    }
    else if (s == 2) {
        printf("·¡Ê°");
    }
    else if (s == 3) {
        printf("ÈþÊ°");
    }
    else if (s == 4) {
        printf("ËÁÊ°");
    }
    else if (s == 5) {
        printf("ÎéÊ°");
    }
    else if (s == 6) {
        printf("Â½Ê°");
    }
    else if (s == 7) {
        printf("ÆâÊ°");
    }
    else if (s == 8) {
        printf("°ÆÊ°");
    }
    else if (s == 9) {
        printf("¾ÁÊ°");
    }
    else if (b != 0 && s == 0 && y != 0) {
        printf("Áã");
    }

    //¸öÎ»
    if (y == 1) {
        printf("Ò¼");
    }
    else if (y == 2) {
        printf("·¡");
    }
    else if (y == 3) {
        printf("Èþ");
    }
    else if (y == 4) {
        printf("ËÁ");
    }
    else if (y == 5) {
        printf("Îé");
    }
    else if (y == 6) {
        printf("Â½");
    }
    else if (y == 7) {
        printf("Æâ");
    }
    else if (y == 8) {
        printf("°Æ");
    }
    else if (y == 9) {
        printf("¾Á");
    }

    int is_z=0;//ÕûÊý²»Îª0
    if (sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || y != 0) {
        is_z = 1;
        printf("Ô²");
    }
    //½Ç
    if (j == 1) {
        printf("Ò¼½Ç");
    }
    else if (j == 2) {
        printf("·¡½Ç");
    }
    else if (j == 3) {
        printf("Èþ½Ç");
    }
    else if (j == 4) {
        printf("ËÁ½Ç");
    }
    else if (j == 5) {
        printf("Îé½Ç");
    }
    else if (j == 6) {
        printf("Â½½Ç");
    }
    else if (j == 7) {
        printf("Æâ½Ç");
    }
    else if (j == 8) {
        printf("°Æ½Ç");
    }
    else if (j == 9) {
        printf("¾Á½Ç");
    }
    else if (j == 0 && f != 0 && is_z==1) {
        printf("Áã") ;
    }
    else if (j == 0 && f == 0 && is_z==1) {
        printf("Õû") ;
    }
    else if (j == 0 && f == 0 && is_z==0) {
        printf("ÁãÔ²Õû") ;
    }
    //·Ö
    if (f == 1) {
        printf("Ò¼·Ö");
    }
    else if (f == 2) {
        printf("·¡·Ö");
    }
    else if (f == 3) {
        printf("Èþ·Ö");
    }
    else if (f == 4) {
        printf("ËÁ·Ö");
    }
    else if (f == 5) {
        printf("Îé·Ö");
    }
    else if (f == 6) {
        printf("Â½·Ö");
    }
    else if (f == 7) {
        printf("Æâ·Ö");
    }
    else if (f == 8) {
        printf("°Æ·Ö");
    }
    else if (f == 9) {
        printf("¾Á·Ö");
    }
    else if (f == 0 && j != 0) {
        printf("Õû");
    }
    printf("\n");
    return 0;
}
