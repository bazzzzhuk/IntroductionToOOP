#include<iostream>
#include<math.h>
using namespace std;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;
	double doubler;
	int numerator;
	int denominator;
public:
	int  get_integer()const
	{
		return integer;
	}
	int  get_numerator()const
	{
		return numerator;
	}
	int  get_denominator()const
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
	//		Constructors		//
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	explicit Fraction(double doubler)
	{
		//double num = doubler - (int)doubler;
		//long double d = num + 1e-10;
		//long long test = 1;
		//int count = 0;
		//while (test != d) //Подсчёт регистров
		//{
		//	d *= 10;
		//	test = (int)d;
		//	if (!(test % 10))break;
		//	count++;
		//}
		//this->integer =(int)doubler;
		//this->numerator = num * pow(10, count);
		//this->denominator = pow(10, count);

		integer = doubler;
		doubler -= integer;
		denominator = 1e+9;
		numerator = doubler * denominator;


		reduce();
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
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstruction:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	///      OPERATORS   ///
	Fraction& operator= (const Fraction& other)// =
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	//		INCREMENTO/DECREMENTO		//
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	const Fraction operator++(int)
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
	const Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	//    TYPE_CAST_OPERATORS	//
	explicit operator int()const
	{
		//to_improper();//Evalueate as a constant
		return integer + numerator / denominator;
	}
	explicit operator double()const
	{
		return integer + numerator / (double)denominator;
	}

	///   Methods  ///
	Fraction  to_improper()
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
	Fraction  inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more == numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
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
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
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
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();

}
///		Condition_operators			//
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return	left.get_numerator() * right.get_denominator() ==
		left.get_denominator() * right.get_numerator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return  left.get_numerator() * right.get_denominator() >
		left.get_denominator() * right.get_numerator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return  left.get_numerator() * right.get_denominator() <
		left.get_denominator() * right.get_numerator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& os, Fraction& obj)
	{
	/*int i, n, d;
	os >> i >> n >> d;
	obj.set_integer(i);
	obj.set_numerator(n);
	obj.set_denominator(d);*/

	const int SIZE = 256;
	char buffer[SIZE] = {};
	//os >> buffer;
	os.getline(buffer, SIZE);
	const char delimetrs[] = "(/ ,)";
	int n = 0;
	int numbers[3] = {};
	for (
		char* pch = strtok(buffer, delimetrs); 
		pch&&n<3; 
		pch = strtok(NULL, delimetrs)
		)
		numbers[n++] = atoi(pch);
	//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;
	switch (n)
	{
	case 0: obj = Fraction{}; break;
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0],numbers[1]); break;
	case 3: obj = Fraction(numbers[0],numbers[1],numbers[2]); break;
	}
	return os;//не совсем понятный синтаксис, но интуитивно сделал, работает.
	}
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CHECK
//#define CONDITION_CHECK
#define STREAM_CHECK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_DAY

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
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	C = A / B;
	C.print();

	A *= B;
	A.print();

	A /= B;
	A.print();

	C = A + B;
	C.print();

	C = B - A;
	C.print();

	C += A;
	C += A;
	C.print();

	C -= B;
	C.print();

#endif
#ifdef INCREMENTO_DECREMENTO_CHECK
	Fraction A(2, 3, 4);
	Fraction B = ++A;
	A.print();
	B.print();
	B--;
	B = --A;
	A.print();
	B.print();

#endif
#ifdef CONDITION_CHECK
	//Fraction A(2, 3, 4);
	//A.print();
	//Fraction B(2, 3, 4);
	//B.print();
	cout << "!= " << (Fraction(1, 2) != Fraction(2, 3)) << endl;
	/*cout <<"> " << (A > B) << endl;
	cout << "< " << (A < B) << endl;
	cout <<">=" << (A >= B) << endl;*/
#endif
#ifdef STREAM_CHECK
	/*for (Fraction i(9, 1, 2); i > 0; --i)
{
	i.print();
}*///delete?
	Fraction A(2, 3, 4);
	cout << "enter fraction: ";
	cin >> A;
	cout << A << endl;
#endif // STREAM_CHECK
#ifdef TYPE_CONVERSION_BASICS

	int a = 2;//no conversion
	double b = 3;	 //conversion from less to more
	int c = b;		 //conversion from more to less without data loss
	int d = 5.5;	 //conversion from more to less with data loss

#endif 
#ifdef CONVERSION_FROM_OTHER_TO_CLASS

	/*
	1. From other to Class - из других типов в наш
	2. From Class to other - из нашего типа

	*/
	Fraction A = (Fraction)5;//Single-Argument constructor (from less to more)
	cout << A << endl;
	Fraction B;
	B = Fraction(8);
	//Single-arg-constructor(From less to more)
  //singleArgConstr создает из 8 временный объект
 // а оператор присваивания просто записывает его в существующий объект В


#endif
#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	A.to_improper().print();
	int a = (int)A;
	cout <<"int a= " << a << endl;

	double b = (double)A;
	cout <<"double b= " << b << endl;
#endif 
#ifdef HAVE_A_NICE_DAY
	Fraction A = (Fraction)2.75;
	cout<<"A= " << A << endl;
#endif


}