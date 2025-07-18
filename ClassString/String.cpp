#include "String.h"


///////////////////////////////////////////////////////////////////
////////    Определения класса (Class definition)		    //////
/////////////////////////////////////////////////////////////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//   constructor   //
String::String(int size) : size(size), str(new char[size] {})
{
	//создаёт пустую строку 80 байт
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1; // функция возвращает размер строки в символах,
	//+1 нужен чтобы выделилась память под NULL-terminator
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//this->str = other.str; //Shallow copy
	//DeepCopy:
	/*this->size = other.size;
	this->str = new char[size] {};*/
	/*for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}*/
	cout << "CopyConstructor:\t" << this << endl;
}
String& String::operator=(String& other)
{
	//Проверяем, не является ли тот объект этим объектом.
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	//delete old memory
	delete[]str;
	//shallowCopy
	this->size - other.size;
	this->str = other.str;
	//обнуляем принимаемый объект
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
String::String(String&& other) :size(size), str(other.str)
{
	//moveConstructor
	/*this->size = other.size;
	this->str = other.str;*/
	//обнуляем принимаемый объект для того чтобы предотвратить удаление его ресурсов деструктором
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String() {
	delete[] str;
	str = nullptr;
	size = 0;
	cout << "Destructor:\t\t" << this << endl;
}
// Methods
void String::print()const
{
	cout << "Size: \t" << size << endl;
	cout << "Str: \t" << str << endl;
}
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
///////////////////////////////////////////////////////////////////
////////   Конец Определения класса (Class definition end)  //////
/////////////////////////////////////////////////////////////////
