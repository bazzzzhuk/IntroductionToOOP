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
	double distance(double a, double b)const
	{
		double gptnz = sqrt(a * a + b * b);
		return gptnz;
	}
	double distance(double a, double b, double aa, double bb)const
	{
		double aaa, bbb;
		if (a > aa)aaa = a - aa; else aaa = aa - a;
		if (b > bb)bbb = b - bb; else bbb = bb - b;

		double gptnz = sqrt(aaa * aaa + bbb * bbb);
		return gptnz;
	}
	void Graf(double x, double y, double xx, double yy)
	{
		setlocale(LC_ALL, "C");
		cout << '\x20' << "Y" << endl;
		cout << '\x20' << '\x1E' << endl;
		cout << '\x20' << '\xB3' << endl;
		for (int i = ((y > yy ? y : yy)+1); i > 0; i--)
		{
			
			if (i == (y +1) && i == (yy + 1))
			{
				cout << i << '\xB3';
				for (int i = 1; i < (x > xx ? x : xx)+1; i++)
				{
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
					cout << '\x20';
				}
				cout << endl;
				continue;
			}
			if (i == y&&i==yy)
			{
				cout << i << '\xB3';
				for (int i = 1; i < (x > xx ? x : xx)+1; i++)
				{
					if (i == x)
					{
						cout << '\xFD';
						continue;
					}
					if (i == xx)
					{
						cout << '\xFD';
						continue;
					}
					cout << '\x20';
				}
				cout << endl;
				continue;
			}
			if (i == y&&i!=yy)
			{
				cout << i << '\xB3';
				for (int i = 0; i < x - 1; i++)cout << '\x20';
				cout << "\xFD" << "a" << endl;
				continue;
			}
			if (i == yy&&i!=y)
			{
				cout << i << '\xB3';
				for (int i = 0; i < xx - 1; i++)cout << '\x20';
				cout << "\xFD" << "b" << endl;
				continue;
			}
			cout << i << '\xB3' << endl;
		}
		cout << '\x20' << '\xC5';
		for (int i = 0; i < (x > xx ? x : xx) + 2; i++)cout << '\xC4';
		cout << '\x10' << "X" << endl << '\x20' << '\x20';
		for (int i = 1; i < (x > xx ? x : xx) + 2; i++)cout << i;
		cout << endl;
		setlocale(LC_ALL, "");
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
	cout << "Введите координаты первой точки  (x,y) : "; cin >> x >> y;
	cout << "Введите координаты второй точки (xх,yу): "; cin >> xx >> yy;
	/*if (x != 0 && y != 0)
	{*/
		A.set_x(x);
		A.set_y(y);
	/*}
	if (xx != 0 && yy != 0)//хотел перегрузить
	{*/
		A.set_xx(xx);
		A.set_yy(yy);
	//}

	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.Graf(A.get_x(), A.get_y(), A.get_xx(), A.get_yy());
	cout << "Расстояние от нуля до точки: " << A.distance(A.get_x(), A.get_y()) << endl;
	cout << "Расстояние между точками   : " << A.distance(A.get_x(), A.get_y(), A.get_xx(), A.get_yy()) << endl;
}