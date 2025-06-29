#include<iostream>
#include <math.h>
using namespace std;

class Point
{
	double x;
	double y;
	double xx;
	double yy;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double get_xx()const
	{
		return xx;
	}
	double get_yy()const
	{
		return yy;
	}
	void set_xx(double xx)
	{
		this->xx = xx;
	}
	void set_yy(double yy)
	{
		this->yy = yy;
	}
	double distance(double a,double b)const
	{
		double gptnz=sqrt(a * a + b * b);
		return gptnz;
	}
	double distance(double a,double b,double aa,double bb)const
	{
		double aaa, bbb;
		if (a > aa)aaa = a - aa; else aaa = aa - a;
		if (b > bb)bbb = b - bb; else bbb = bb - b;

		double gptnz=sqrt(aaa * aaa + bbb * bbb);
		return gptnz;
	}
};

//#define SRTUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef SRTUCT_POINT
	Point A; // Объявление переменной 'А' типа Point
			// Создание объекта 'А' структуры Point
			// Создание экземпляра 'А' структуры Point
			// 'A' is instance of struct 'Point'
			// Instantiate - создать объект.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif

	Point A;
	double x, y, xx, yy;
	cout << "Введите координаты первой точки (x,y): "; cin >> x >> y;
	cout << "Введите координаты второй точки (xх,yу): "; cin >> xx >> yy;
	A.set_x(x);
	A.set_y(y);
	A.set_xx(xx);
	A.set_yy(yy);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	
	cout << "Расстояние до точки: " << A.distance(A.get_x(), A.get_y())<<endl;
	cout << "Расстояние между точками: " << A.distance(A.get_x(), A.get_y(), A.get_xx(), A.get_yy()) << endl;
}