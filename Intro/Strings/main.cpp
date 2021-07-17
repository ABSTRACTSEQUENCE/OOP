#include<iostream>
#include<string>
using namespace std;
struct String			//Пока что структура, после завершения дз поработаю над инкапсуляцией.
{
	string Str;
	//methods
	void print() {cout << Str; }
	//constructors
	String()
	{
		const int SIZE = 80;
		Str[SIZE];
		cout << "\nDefault Constructor\n";
	}
	/*String(const char Hello)
	{
		Str = "Hello";
	}*/
	~String()
	{
		cout << "\nDesturctor\n";
	}
};
void main()
{
	String str;	//Создает пустую строку размером 80 Байт   DONE
	String str1 = "Hello";
	/*cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;*/

	/*
	Извините, не успел закончить домашку к дедлайну, поэтому выложу недоделанную
	Я буду делать дз и обновлять гитхаб время от времени. 
	*/
	
}