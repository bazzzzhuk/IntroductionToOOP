#include<iostream>
using namespace std;

class String
{

	int n = 1;
	char* str;
public:
	int get_n()const
	{
		return n;
	}
	char* get_string()const
	{
		return str;
	}
	char& get_string(int n)const
	{
		return str[n];
	}
	void set_string(char* str)
	{
		for (int i = 0; this->str[i]; i++)
		{
			this->str[i] = str[i];
		}
	}
	void set_n(int n)
	{
		this->n = n;
	}
	String()
	{
		// char* str = new char[n];
		cout << "def constr!" << endl;
	}
	int length()
	{
		int lngth = 0;
		for (int i = 0; this->str[i]; i++)lngth++;
		return lngth;
	}
	int& length(const char* str)
	{
		int lngth = 0;
		for (int i = 0; str[i]; i++)lngth++;
		return lngth;
	}
	int& length(char* str)
	{
		int lngth = 0;
		for (int i = 0; str[i]; i++)lngth++;
		return lngth;
	}
	String(const char* other)
	{ 
		n = length(other);
		cout << "\nmmm= " << n << endl;
		char* buf = new char[n + 1];
		for (int i = 0; other[i]; i++)buf[i] = other[i];
		delete[] str;
		str = buf;
		set_n(n);
		buf = nullptr;
		cout << "Create single arg:\t" << this << endl;
	}
	String(char* other)
	{ 
		n = length(other);
		cout << "\nnnn= " << n << endl;
		char* buf = new char[n + 1];
		for (int i = 0; other[i]; i++)buf[i] = other[i];
		delete[] str;
		str = buf;
		set_n(n);
		buf = nullptr;
		cout << "CCreate single arg:\t" << this << endl;
	}
	~String()
	{
		cout << "\ndelete" <<this<< endl;
		delete[]str;
		//str = nullptr;
	}
	 //=======
	String& operator=(const char* other)
	{
		n = length(other);
		char* buf = new char[n + 1];
		for (int i = 0; i<n; i++)buf[i] = other[i];
		*this = buf;
		delete[] buf;
		buf = nullptr;
		cout << "!!!" << endl;
		return *this;
	}
	/*String operator=(String other)
	{
		n = other.get_n();
		char* buf = new char[n+1];
		for (int i = 0; other.str[i]; i++)buf[i] = other.str[i];
		*this = buf;
		delete[] buf;
		buf = nullptr;
		cout << "!!!" << endl;
		return *this;
	}*/
	 //+++++++
	//String& operator+(String& other)
	//{
	//	int n1 = this->n;
	//	cout << "n1 = " << n1 << endl;
	//	int n2 = other.n;
	//	cout << "n2 = " << n2 << endl;
	//	int n = n1 + n2;
	//	char* buf = new char[n+1];
	//	for (int i = 0; i < n1; i++)buf[i] = this->get_string(i);
	//	for (int i = n1; i < n; i++)buf[i] = other.get_string(i - n1);
	//	cout << "nn= " << n << endl;
	//	for (int i = 0; i < n; i++) this->str[i] = buf[i], cout << "buf[i]= " << buf[i] << endl;
	//	cout << "n= " << n << endl;
	//	this->str=buf;
	//	//*this = buf;
	//	/*delete[] buf;
	//	buf = nullptr;*/
	//	//for (int i = 0; i < n; i++)cout << this[i];
	//	return *this;
 //		//return *this;
	//}
	void Print()
	{
		/*if (this->length() == 0)cout << "";
		else */for (int i = 0; i<n; i++)
		{
			cout << this->str[i];
		}
	}
};
	String operator+(String& str1, String& str2)
	{
		int n1 = str1.get_n();
		cout << "n1 = " << n1 << endl;
		int n2 = str2.get_n();
		cout << "n2 = " << n2 << endl;
		int n= n1+n2;
		char* buf = new char[n+1];
		for (int i = 0; i < n1; i++)buf[i] = str1.get_string(i);
		for (int i = n1; i < n; i++)buf[i] = str2.get_string(i-n1);
		for (int i =0; i < n; i++)cout << buf[i];
		cout << "\nmmm= " << n << endl;
		//delete[] buf;
		//buf = nullptr;
		return String(buf);
	}

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	str1.Print();
	cout << " ";
	String str2 = "Baz";
	str2.Print();

	cout << endl;
	//(str1 + str2).Print();
	String str3 = str1 + str2;
	str3.Print();
}