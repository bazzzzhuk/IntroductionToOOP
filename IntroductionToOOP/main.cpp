#include<iostream>
#include <math.h>
#define tab ((i >= 10) ? " " : "  ")
#define tab2 ((i >= 10) ? "" : " ")
using namespace std;
//

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
	
	double distance(double a, double b)const
	{
		return sqrt(a * a + b * b);
	}
};

//#define SRTUCT_POINT

void Graf(double x, double y, double xx, double yy)
{
	setlocale(LC_ALL, "C");

	cout << "   " << "Y" << endl;
	cout << "   " << '\x1E' << endl;
	cout << "   " << '\xB3' << endl;
	for (int i = ((y > yy ? y : yy) + 1); i > 0; i--)
	{
		if (i == (y + 1) && i == (yy + 1))
		{
			cout << tab << i << '\xB3';
			for (int i = 1; i < (x > xx ? x : xx) + 1; i++)
			{
				if (i == x && i == xx)
				{
					cout << "a&b";
					continue;
				}
				if (i == x)
				{
					cout << "a";
					continue;
				}
				if (i == xx)
				{
					cout << "b";
					continue;
				}
				cout << '\x20' << '\x20';
			}
			cout << endl;
			continue;
		}
		if (i == y && i == yy)
		{
			cout << tab << i << '\xB3';
			for (int i = 1; i < (x > xx ? x : xx) + 1; i++)
			{
				if (i == x)
				{
					cout << '\x0F';
					continue;
				}
				if (i == xx)
				{
					cout << '\x0F';
					continue;
				}
				cout << '\x20' << ".";
			}
			cout << endl;
			continue;
		}
		if (i == y && i != yy)
		{
			cout << ((i >= 10) ? " " : "  ") << i << '\xB3';
			for (int i = 0; i < x - 1; i++)cout << '\x20' << ".";
			cout << "\x0F" << "a" << endl;
			continue;
		}
		if (i == yy && i != y)
		{
			cout << ((i >= 10) ? " " : "  ") << i << '\xB3';
			for (int i = 0; i < xx - 1; i++)cout << '\x20' << ".";
			cout << "\x0F" << "b" << endl;
			continue;
		}
		cout << ((i >= 10) ? " " : "  ") << i << '\xB3';
		for (int ii = 1; ii < (x > xx ? x : xx) + 1; ii++)
		{
			if ((ii == x && i < y) || (ii == xx && i < yy))cout << ". "; else cout << "  ";
		}
		cout << endl;
	}
	cout << "   " << '\xC5';
	for (int i = 0; i < (x > xx ? x : xx) + 2; i++)cout << '\xC4' << '\xC4';
	cout << '\x10' << "X" << endl << "    ";
	for (int i = 1; i < (x > xx ? x : xx) + 2; i++)cout << i << tab2;
	cout << endl;
	setlocale(LC_ALL, "");
}


double distance(Point A, Point B)
{
	double xx = A.get_x() - B.get_x();
	double yy = A.get_y() - B.get_y();
	return sqrt(xx * xx + yy * yy);
}

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
	Point B;

	Point* pA = &A;
	Point* pB = &B;
	//double x, y, xx, yy;
	double x = 4, y = 4, xx = 11, yy = 4;/*
	cout << "Введите координаты первой точки, значениями до 99  (x,y) : "; cin >> x >> y;
	cout << "Введите координаты второй точки, значениями до 99 (xх,yу): "; cin >> xx >> yy;*/
	
		A.set_x(x);
		A.set_y(y);
	
		B.set_x(xx);
		B.set_y(yy);
	
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	Graf(A.get_x(), A.get_y(), B.get_x(), B.get_y());
	cout << "Расстояние от нуля до точки: " << A.distance(A.get_x(), A.get_y()) << endl;
	cout << "Расстояние от нуля до точки B: " << B.distance(B.get_x(), B.get_y()) << endl;
	cout << "Расстояние между точками  A&B  : " << distance(A,B) << endl;
}