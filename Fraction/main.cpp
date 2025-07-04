#include<iostream>
using namespace std;

// 1. Для класса 'Fraction' перегрузить все арифметические операторы : / , +, -; DONE
// 2. Перегрузить составные присваивания : +=, -=, *=, /=;
// 3. Перегрузить Incremento / Decremento(++/ --);
// 4. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;

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
		cout << "CopyAssignment:\t" << this << endl;
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
///    OPERATORS_OUT   ///
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

//#define CONSTRUCTORS_CHECK
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


}