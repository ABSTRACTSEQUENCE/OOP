//#include<iostream>
//using namespace std;
#include "human.h"
#include "student.h"
#include "teacher.h"
#include"grad.h"
#define delimiter "\n----------------------------------------------\n"
//#define poly
#define INHERITANCE
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	cout << "Наследование" << endl;
	Human vasya("Тупенко", "Василий", 22);
	vasya.print();

	cout << delimiter << endl;
	Student student("Иванов", "Федор", 25, "РПО", "ВБУ_011", 90);
	student.print();

	cout << delimiter << endl;
	Teacher	teacher("Einstein", "Albert", 142, "Astronomy", 112);
	teacher.print();

	cout << delimiter << endl;
	Graduate graduate("Musk", "Elon", 34, "Car building", "VBU_011", 98, "Колонизация марса");
	graduate.print();
#endif // INHERITANCE
#ifdef poly
	Human* group[] =
	{
		new Student("Галлямутдинова", "Альбина", 25, "РПО", "ВБУ_011", 95),
		new Graduate("Ремизов", "Дмитрий", 27, "РПО", "ВБУ_011", 95, "Фиг его значет ;-)"),
		new Teacher("Einstein", "Albert", 142, "Astronomy", 112),
		new Student("Сорокина", "Мария", 22, "РПО", "ВБУ_011", 98)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}
#endif
	/*typedef int datatype;
	datatype arr[] = { 2,3,5,8,13,21,34 };
	for (int i = 0; i < sizeof(arr)/sizeof(datatype); i++) cout << arr[i] << endl;*/
}