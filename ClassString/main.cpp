#include<iostream>
using namespace std;

class String
{
	int size;//размер строки в байтах (с учётом NULL-Terminator)
	char* str;//адрес строки в динамической памяти
public:
	//   constructor   //
	explicit String(int size = 80)
	{
		//создаёт пустую строку 80 байт
		this->size = size;
		this->str = new char[size] {};
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1; // функция возвращает размер строки в символах,
		//+1 нужен чтобы выделилась память ппод нуль-терминатед
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;

	}
	// Methods
	void print()const
	{
		cout << "Size: \t" << size << endl;
		cout << "Str: \t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	String str1;
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";
	str3.print();
}