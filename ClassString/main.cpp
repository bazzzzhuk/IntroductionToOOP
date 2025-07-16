#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;//размер строки в байтах (с учётом NULL-Terminator)
	char* str;//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

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
		//+1 нужен чтобы выделилась память под NULL-terminator
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;

	}
	String(const String& other)//Shallow copy
	{
		//this->str = other.str;
		//DeepCopy:
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	String& operator=(String& other)
	{
		//Проверяем, не является ли тот объект этим объектом.
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size + 1] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	~String() {
		delete[] str;
		str = nullptr;
		size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}
	// Methods
	void print()const
	{
		cout << "Size: \t" << size << endl;
		cout << "Str: \t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String rezult(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		rezult[i] = left[i];
	//rezult.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		rezult[i + left.get_size() - 1] = right[i];
	//rezult.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return rezult;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
#define CONSTR_CHECK
//#define COPY_SEMANTIC_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTR_CHECK
	String str1;
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = "World";
	cout << str4 << endl;

	String str5 = str3 + str4;
	cout << str5 << endl;
#endif // CONSTR_CHECK
#ifdef COPY_SEMANTIC_CHECK
	String str1 = "Hello";
	String str3 = "World";
	cout << str1 << endl;
	String str2 = str1;
	cout << "str2= " << str2 << endl;
	str2 = str3;
	cout << "str2= " << str2 << endl;
#endif


}