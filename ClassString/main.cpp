#include"String.h"

//#define CONSTR_CHECK
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

	String str5;
	str5 = str3 + str4;
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

	String str1;//default
	str1.print();

	String str2(5);//singleArgConstructor(int)
	str2.print();

	String str3 = "Hello";//singleArgument
	str3.print();

	String str4();//в этой строке Не вызыввается дэфолтконстр и не создаётся объект
	//здесь объявляется функция str4 которая ничего не принимает
	//и возвращает значение типа string
	// str4 не является объектом.
	//круглые скобки не делают явный вызов конструктора по умолчанию,
	//если есть необходимость явно вызвать конструктор по умолчанию, 
	//то это можно сделать при помощи фигурных скобок
	
	String str5{};//а это строка уже явно вызывает defaultConstructor()
	str5.print();

	String str6{ 6 };//singleargconstructor(int)
	str6.print();

	String str7{ "World" };
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();

	String str10{ str9 };
	str10.print();

	//Фигурные скобки для вызова конструктора следует использовать с большой осторожностью
	//

	String str11 = str3 + str8;
	str11.print();

	cout << str11 << endl;

}