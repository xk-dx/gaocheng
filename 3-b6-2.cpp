/* 2354218 Ğ¤¼ÑÍ® ¼Æ¿Æ */
#include <iostream>
using namespace std;

int main()
{
	double a;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> a;
	int sy = int(a / 1000000000) % 10;
	int yi = int(a / 100000000) % 10;
	int qw = int(a / 10000000) % 10;
	int bw = int(a / 1000000) % 10;
	int sw = int(a / 100000) % 10;
	int w = int(a / 10000) % 10;
	int q = int(a / 1000) % 10;
	int b = int(a / 100) % 10;
	a /= 100;
	a -= int(a);
	a *= 10000;
	a += 0.001;
	int s = int(a / 1000) % 10;
	int y = int(a / 100) % 10;
	int j = int(a / 10) % 10;
	int f = int(a) % 10;
	//Ê®ÒÚ
	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	if (sy == 1) {
		cout<<"Ò¼Ê°";
	}
	else if (sy == 2) {
		cout<< "·¡Ê°";
	}
	else if (sy == 3) {
		cout<< "ÈşÊ°";
	}
	else if (sy == 4) {
		cout<< "ËÁÊ°";
	}
	else if (sy == 5) {
		cout<< "ÎéÊ°";
	}
	else if (sy == 6) {
		cout<< "Â½Ê°";
	}
	else if (sy == 7) {
		cout<< "ÆâÊ°";
	}
	else if (sy == 8) {
		cout<< "°ÆÊ°";
	}
	else if (sy == 9) {
		cout<< "¾ÁÊ°";
	}
	//ÒÚ
	if (yi == 1) {
		cout<< "Ò¼";
	}
	else if (yi == 2) {
		cout<< "·¡";
	}
	else if (yi == 3) {
		cout<< "Èş";
	}
	else if (yi == 4) {
		cout<< "ËÁ";
	}
	else if (yi == 5) {
		cout<< "Îé";
	}
	else if (yi == 6) {
		cout<< "Â½";
	}
	else if (yi == 7) {
		cout<< "Æâ";
	}
	else if (yi == 8) {
		cout<< "°Æ";
	}
	else if (yi == 9) {
		cout<< "¾Á";
	}
	if (sy != 0 || yi != 0)
		cout<< "ÒÚ";

	//Ç§Íò
	if (qw == 1) {
		cout<< "Ò¼Çª";
	}
	else if (qw == 2) {
		cout<< "·¡Çª";
	}
	else if (qw == 3) {
		cout<< "ÈşÇª";
	}
	else if (qw == 4) {
		cout<< "ËÁÇª";
	}
	else if (qw == 5) {
		cout<< "ÎéÇª";
	}
	else if (qw == 6) {
		cout<< "Â½Çª";
	}
	else if (qw == 7) {
		cout<< "ÆâÇª";
	}
	else if (qw == 8) {
		cout<< "°ÆÇª";
	}
	else if (qw == 9) {
		cout<< "¾ÁÇª";
	}
	else if (qw == 0 && (sy != 0 || yi != 0) && (sw != 0 || bw != 0 || w != 0)) {
		cout<< "Áã";
	}
	//°ÙÍò
	if (bw == 1) {
		cout<< "Ò¼°Û";
	}
	else if (bw == 2) {
		cout<< "·¡°Û";
	}
	else if (bw == 3) {
		cout<< "Èş°Û";
	}
	else if (bw == 4) {
		cout<< "ËÁ°Û";
	}
	else if (bw == 5) {
		cout<< "Îé°Û";
	}
	else if (bw == 6) {
		cout<< "Â½°Û";
	}
	else if (bw == 7) {
		cout<< "Æâ°Û";
	}
	else if (bw == 8) {
		cout<< "°Æ°Û";
	}
	else if (bw == 9) {
		cout<< "¾Á°Û";
	}
	else if (qw != 0 && bw == 0 && (sw != 0 || w != 0)) {
		cout<< "Áã";  // Ç§Î»´æÔÚµ«°ÙÎ»ÎªÁãÊ±Êä³ö¡°Áã¡±
	}
	//Ê®Íò
	if (sw == 1) {
		cout<< "Ò¼Ê°";
	}
	else if (sw == 2) {
		cout<< "·¡Ê°";
	}
	else if (sw == 3) {
		cout<< "ÈşÊ°";
	}
	else if (sw == 4) {
		cout<< "ËÁÊ°";
	}
	else if (sw == 5) {
		cout<< "ÎéÊ°";
	}
	else if (sw == 6) {
		cout<< "Â½Ê°";
	}
	else if (sw == 7) {
		cout<< "ÆâÊ°";
	}
	else if (sw == 8) {
		cout<< "°ÆÊ°";
	}
	else if (sw == 9) {
		cout<< "¾ÁÊ°";
	}
	else if (bw != 0 && sw == 0 && w != 0) {
		cout<< "Áã";  // °ÙÎ»´æÔÚµ«Ê®Î»ÎªÁãÊ±Êä³ö¡°Áã¡±
	}

	// ÅĞ¶Ï²¢×ª»»¸öÎ»
	if (w == 1) {
		cout<< "Ò¼";
	}
	else if (w == 2) {
		cout<< "·¡";
	}
	else if (w == 3) {
		cout<< "Èş";
	}
	else if (w == 4) {
		cout<< "ËÁ";
	}
	else if (w == 5) {
		cout<< "Îé";
	}
	else if (w == 6) {
		cout<< "Â½";
	}
	else if (w == 7) {
		cout<< "Æâ";
	}
	else if (w == 8) {
		cout<< "°Æ";
	}
	else if (w == 9) {
		cout<< "¾Á";
	}
	if (sw != 0 || bw != 0 || qw != 0 || w != 0)
		cout<< "Íò";

	//Ç§
	if (q == 1) {
		cout<< "Ò¼Çª";
	}
	else if (q == 2) {
		cout<< "·¡Çª";
	}
	else if (q == 3) {
		cout<< "ÈşÇª";
	}
	else if (q == 4) {
		cout<< "ËÁÇª";
	}
	else if (q == 5) {
		cout<< "ÎéÇª";
	}
	else if (q == 6) {
		cout<< "Â½Çª";
	}
	else if (q == 7) {
		cout<< "ÆâÇª";
	}
	else if (q == 8) {
		cout<< "°ÆÇª";
	}
	else if (q == 9) {
		cout<< "¾ÁÇª";
	}
	else if (q == 0 && (sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0) && (b != 0 || s != 0 || y != 0)) {
		cout<< "Áã";
	}
	//°Ù
	if (b == 1) {
		cout<< "Ò¼°Û";
	}
	else if (b == 2) {
		cout<< "·¡°Û";
	}
	else if (b == 3) {
		cout<< "Èş°Û";
	}
	else if (b == 4) {
		cout<< "ËÁ°Û";
	}
	else if (b == 5) {
		cout<< "Îé°Û";
	}
	else if (b == 6) {
		cout<< "Â½°Û";
	}
	else if (b == 7) {
		cout<< "Æâ°Û";
	}
	else if (b == 8) {
		cout<< "°Æ°Û";
	}
	else if (b == 9) {
		cout<< "¾Á°Û";
	}
	else if (q != 0 && b == 0 && (s != 0 || y != 0)) {
		cout<< "Áã";  // Ç§Î»´æÔÚµ«°ÙÎ»ÎªÁãÊ±Êä³ö¡°Áã¡±
	}
	//Ê®
	if (s == 1) {
		cout<< "Ò¼Ê°";
	}
	else if (s == 2) {
		cout<< "·¡Ê°";
	}
	else if (s == 3) {
		cout<< "ÈşÊ°";
	}
	else if (s == 4) {
		cout<< "ËÁÊ°";
	}
	else if (s == 5) {
		cout<< "ÎéÊ°";
	}
	else if (s == 6) {
		cout<< "Â½Ê°";
	}
	else if (s == 7) {
		cout<< "ÆâÊ°";
	}
	else if (s == 8) {
		cout<< "°ÆÊ°";
	}
	else if (s == 9) {
		cout<< "¾ÁÊ°";
	}
	else if (b != 0 && s == 0 && y != 0) {
		cout<< "Áã";  // °ÙÎ»´æÔÚµ«Ê®Î»ÎªÁãÊ±Êä³ö¡°Áã¡±
	}

	// ÅĞ¶Ï²¢×ª»»¸öÎ»
	if (y == 1) {
		cout<< "Ò¼";
	}
	else if (y == 2) {
		cout<< "·¡";
	}
	else if (y == 3) {
		cout<< "Èş";
	}
	else if (y == 4) {
		cout<< "ËÁ";
	}
	else if (y == 5) {
		cout<< "Îé";
	}
	else if (y == 6) {
		cout<< "Â½";
	}
	else if (y == 7) {
		cout<< "Æâ";
	}
	else if (y == 8) {
		cout<< "°Æ";
	}
	else if (y == 9) {
		cout<< "¾Á";
	}
	bool is_z(sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || y != 0);//ÕûÊı²¿·Ö²»ÎªÁã
	if (is_z)
		cout<< "Ô²";

	//Ğ¡Êı

	if (j == 1) {
		cout<< "Ò¼½Ç";
	}
	else if (j == 2) {
		cout<< "·¡½Ç";
	}
	else if (j == 3) {
		cout<< "Èş½Ç";
	}
	else if (j == 4) {
		cout<< "ËÁ½Ç";
	}
	else if (j == 5) {
		cout<< "Îé½Ç";
	}
	else if (j == 6) {
		cout<< "Â½½Ç";
	}
	else if (j == 7) {
		cout<< "Æâ½Ç";
	}
	else if (j == 8) {
		cout<< "°Æ½Ç";
	}
	else if (j == 9) {
		cout<< "¾Á½Ç";
	}
	else if (j == 0 && f != 0 && is_z) {
		cout<< "Áã";
	}
	else if (j == 0 && f == 0 && is_z) {
		cout<< "Õû";
	}
	else if (j == 0 && f == 0 && !is_z) {
		cout<< "ÁãÔ²Õû";
	}
	//·Ö
	if (f == 1) {
		cout<< "Ò¼·Ö";
	}
	else if (f == 2) {
		cout<< "·¡·Ö";
	}
	else if (f == 3) {
		cout<< "Èş·Ö";
	}
	else if (f == 4) {
		cout<< "ËÁ·Ö";
	}
	else if (f == 5) {
		cout<< "Îé·Ö";
	}
	else if (f == 6) {
		cout<< "Â½·Ö";
	}
	else if (f == 7) {
		cout<< "Æâ·Ö";
	}
	else if (f == 8) {
		cout<< "°Æ·Ö";
	}
	else if (f == 9) {
		cout<< "¾Á·Ö";
	}
	else if (f == 0 && j != 0) {
		cout<< "Õû";
	}
	cout<<endl;
	return 0;
}





