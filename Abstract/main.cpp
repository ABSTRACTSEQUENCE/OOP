#include <iostream>
using namespace std;

class animal
{
public:
	virtual void sound() = 0; // Pure Virtual func
	/*Мы не знаем как передвигается наше ТС, пока не узнаем какое именно это ТС
	поэтому определение этой функции равно нулю
	Если в классе есть хотя-бы один чисто виртуальный метод, то класс будет абстрактным*/
};
class cat : public animal
{
public:
	void sound() { cout << "mEoW" << endl; }
};
class dog : animal
{
public:
	void sound() {cout << "bArK" << endl; }
};
void main()
{
//	animal animal;		//Can't instantiate abstract class
	cat cat;
	cat.sound();
	dog shaurma;
	shaurma.sound();
}	