#include<iostream>
using namespace std;

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//		Constructors	//
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	//    CopyConstructor    //
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstruction:\t" << this << endl;
	}
	//    Destructor    //
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	///    OPERATORS_IN   ///
	Fraction& operator=(const Fraction& other)// =
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
//  compound assignments operators  //
	Fraction operator+=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = (this->numerator * other.denominator + other.numerator * this->denominator);
		this->denominator = this->denominator * other.denominator;

		this->to_proper();
		other.to_proper();
		this->to_simplifying();
		other.to_simplifying();

		return *this;
	}
	Fraction operator-=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = (this->numerator* other.denominator - other.numerator * this->denominator);
		this->denominator = this->denominator * other.denominator;

		this->to_proper();
		other.to_proper();
		this->to_simplifying();
		other.to_simplifying();

		return *this;
	}
	Fraction operator/=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = this->numerator * other.denominator;
		this->denominator = this->denominator * other.numerator;

		this->to_proper();
		other.to_proper();
		this->to_simplifying();
		other.to_simplifying();

		return *this;
	}
	Fraction operator*=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = this->get_numerator() * other.get_numerator();
		this->denominator = this->get_denominator() * other.get_denominator();

		this->to_proper();
		other.to_proper();
		this->to_simplifying();
		other.to_simplifying();

		return *this;
	}
	///		Methods	   ///
	Fraction to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction to_simplifying()
	{
		int X = numerator;
		int Y = denominator;
		if (X <= 1 || Y <= 1)return *this;
		while (X != Y)if (X > Y)X = X - Y; else Y = Y - X;
		//cout << "X= " << X << endl;
		numerator=numerator / X;
		denominator=denominator/ X;
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};
///     OPERATORS_OUT_OF_CLASS     ///
//  overload arithmetic operators  //
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*
	Fraction rezult;
	rezult.set_numerator(left.get_numerator() * right.get_numerator());
	rezult.set_denominator(left.get_denominator() * right.get_denominator());
	return rezult;*/

	/*Fraction rezult
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	rezult.to_proper();
	return rezult;
	*/

	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(
		((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator())),
		(left.get_denominator() * right.get_denominator())
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(
		((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator())),
		(left.get_denominator() * right.get_denominator())
	).to_proper();
}
//		comparison operators	//
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	bool check = (left.get_numerator() == right.get_numerator()&&left.get_denominator() == right.get_denominator());
	left.to_proper();
	right.to_proper();
	return check;
}
bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() / left.get_denominator()) > (right.get_numerator()/right.get_denominator()));
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() / left.get_denominator()) >= (right.get_numerator()/right.get_denominator()));
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() / left.get_denominator()) < (right.get_numerator() / right.get_denominator()));
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() / left.get_denominator()) <= (right.get_numerator() / right.get_denominator()));
}
//#define CONSTRUCTORS_CHECK
#define FRACTION_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif
#ifdef FRACTION_CHECK
	Fraction A(1, 2, 3);
	A.print();
	Fraction B(2, 3, 4);
	B.print();

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	Fraction Plus = A + B;
	Plus.print();

	Fraction Minus = A - B;
	Minus.print();
	cout << "+=" << endl;

	A.print();
	B.print();
	A += B;
	B += A;
	A.print();
	B.print();

	B -= A;
	A.print();
	B.print();

	A -= B;
	A.print();
	B.print();

	A *= B;
	A.print();
	B.print();
	
	A /= B;
	A.print();
	B.print();

	
	A = ++B++;
	A.print();
	B.print();

	B = A++;
	A.print();
	B.print();

	A--;
	B = --A;
	A.print();
	B.print();

	cout << "== "<<(Fraction(2,3) == Fraction(2,3))<<endl;
	cout << "!= "<<(Fraction(2,3) != Fraction(2,4))<<endl;
	cout << "> "<<(Fraction(7, 3) > Fraction(3, 2, 4)) << endl;
	cout << "< "<<(Fraction(2,7, 3) < Fraction(2, 4)) << endl;
	cout << ">= "<<(Fraction(2, 4) >= Fraction(2, 4)) << endl;
	cout << "<= "<<(Fraction(1,2, 4) <= Fraction(2, 4)) << endl;
#endif
}