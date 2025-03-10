/* 2354218 Ф��ͮ �ƿ� */
#pragma once

/* ���������Ҫ��ͷ�ļ�������ռ� */

/* point��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class point {
private:
	int x;
	int y;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	int getx() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ 
	{
		return x;
	}
	int gety() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ
	{
		return y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	void set(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
};

/* triangle��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		double s;
		s=fabs((double(p1.getx() * p2.gety() + p2.getx() * p3.gety() + p3.getx() * p1.gety() - p1.getx() * p3.gety() - p2.getx() * p1.gety() - p3.getx() * p2.gety())) / 2);
		if (s == 0)
			return -1;
		else
			return s;
	}
	/* ���캯������ʵ�֣���׼���� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};
