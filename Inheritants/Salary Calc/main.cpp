#include <iostream>
using namespace std;
//На организации есть два типа сотрудников - с почасовой и помесячной оплатой.
//Необходимо расчитать зарплату для отдела из пяти сотрудников.
const string random(bool value)
{
	if (value)
	{	
		const string fnames[5]{ "Ivan", "John", "Adam","Pavel", "Josh"};
		int random = rand() % 5;
		return fnames[random];
	}
	else if (!value)
	{
		const string lnames[5]{ "Petrov", "Kuzmin", "Marston", "Ducks", "Brown"};
		int random = rand() % 5;
		return lnames[random];
	}
};
void calc
(
unsigned int one,	unsigned int two,
unsigned int three, unsigned int four,
unsigned int five)
{
	cout << "Total salary per hour: " << one + three << endl;
	cout << "Total salary per month: " << two + four + five << endl;
	cout << "Total salary: " << one + two + three + four + five << endl;
}
//Рандом корявый, иногда генерирует одно и то же, но хотя-бы так
const int srandom(bool value) //true = hour, false = month
{
	int wage;
	if (value)			wage = 100 + rand() % 1000; //hour
	else if (!value)	wage = 10000 + rand() % 50000; //month
	return wage;
}

class employee
{
	string fname;
	string lname;
public:
	//methods
	void print()
	{
		cout << "\nFirst name: " << fname
			<< "\nLast name: " << lname;
	}
	const string get_fname()const
	{
		return fname;
	}
	const string get_lname()const
	{
		return lname;
	}
	void set_fname(const string& value)
	{
		fname = value;
	}
	void set_lname(const string& value)
	{
		lname = value;
	}
	//constructors
	employee
	(
		const string& fname,
		const string& lname
	)
	{
		this->fname = fname;
		this->lname = lname;
	}
};
class hour: public employee 
{ 
	unsigned int salary;
	///////////////////
public:
	unsigned int get_sal()
	{
		return salary;
	}
	void set_sal(unsigned int value)
	{
		salary = value;
	}
	///////////////////
	void print()
	{
		employee::print();
		cout << "\nSalary: " << salary << " per hour" << endl;
	}
	hour
	(
		const string& fname,
		const string& lname,
		unsigned int salary
	):employee(fname, lname)
	{
		set_fname(fname);
		set_lname(lname);
		set_sal(salary);
	}

};
class month : public employee
{
	unsigned int salary_month;
	///////////////////
public:
	unsigned int get_sal()
	{
		return salary_month;
	}
	void set_sal(unsigned int value)
	{
		salary_month = value;
	}
	///////////////////
	void print()
	{
		employee::print();
		cout << "\nSalary: " << salary_month << " per month" << endl;
	}
	month
	(
		const string& fname,
		const string& lname,
		unsigned int salary
	) :employee(fname, lname)
	{
		set_fname(fname);
		set_lname(lname);
		set_sal(salary);
	}
};
	void main()
	{
		srand(time(0));
		hour one(random(true), random(false), srandom(true));
		one.print();
		month two(random(true), random(false), srandom(false));
		two.print();
		hour three(random(true), random(false), srandom(true));
		three.print();
		month four(random(true), random(false), srandom(false));
		four.print();
		month five(random(true), random(false), srandom(false));
		five.print();
		cout << endl;
		calc
		(
			one.get_sal(), two.get_sal(),
			three.get_sal(), four.get_sal(),
			five.get_sal());
	}