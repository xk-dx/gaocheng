/* 2354218 Ф��ͮ �ƿ� */
#pragma once

/* ���������Ҫ��ͷ�ļ�������ռ� */

class triangle;  //�����ǰ������˼��һ�£����������Ŀ����Ϊʲô

/* point��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class point {
private:
	int x;
	int y;
public:
	/* �������ڴ����һ����Ա����������1����,Ҫ������ʵ�� */
	void set(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
	/* ������������Ǹ���Ա�����⣬������������κε����ݳ�Ա�ͳ�Ա�����������Ը�����Ҫ����������� */
	friend triangle;
};

/* triangle��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ���캯������ʵ�֣���׼���� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}

	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��
		   Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		double s;
		s=fabs((double(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y)) / 2);
		if (s == 0)
			return -1;
		else
			return s;
	}

	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};

