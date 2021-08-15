#include"random.h"
//#define month
//На организации есть два типа сотрудников - с почасовой и помесячной оплатой.
//Необходимо расчитать зарплату для отдела из пяти сотрудников.
class employee
{
	string fname;
	string lname;
	unsigned int salary;
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
	const unsigned int get_sal()
	{
		return salary;
	}
	void set_sal(unsigned int value)
	{
		salary = value;
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
		const string& lname,
		unsigned int salary
	)
	{
		this->fname = fname;
		this->lname = lname;
		this->salary = salary;
	}
};
class hour: public employee 
{ 
	unsigned int hours;

public:
	unsigned int get_hours()
	{
		return hours;
	}
	void set_hours(unsigned int value)
	{
		hours = value;
	}

	void print()
	{
		employee::print();
		cout << "\nSalary: " << get_sal() << " per hour"
			 << "\nHours spent: " << hours << endl; 
	}
	hour
	(
		const string& fname,
		const string& lname,
		unsigned int salary,
		unsigned int hours
	):employee(fname, lname, salary)
	{
		set_fname(fname);
		set_lname(lname);
		set_sal(salary);
		set_hours(hours);
	}

};
#ifdef month
class month : public employee
{
	///////////////////
public:
	///////////////////
	void print()
	{
		employee::print();
		cout << "\nSalary: " << salary << " per month" << endl;
	}
	month
	(
		const string& fname,
		const string& lname,
		unsigned int salary
	) :employee(fname, lname,salary)
	{
		set_fname(fname);
		set_lname(lname);
		set_sal(salary);
	}
};
#endif
	void main()
	{
		srand(time(0));
		/*
		hour one(random(true), random(false), srandom(true), hrandom());
		one.print();
		month two(random(true), random(false), srandom(false));
		two.print();
		hour three(random(true), random(false), srandom(true), hrandom());
		three.print();
		month four(random(true), random(false), srandom(false));
		four.print();
		month five(random(true), random(false), srandom(false));
		five.print();
		cout << endl;*/
		hour one(random(true), random(false), srandom(true), hrandom());
		hour two(random(true), random(false), srandom(true), hrandom());
		hour department_1[]{ one, two };
		department_1[1].print();
		cout << "\nSalary: " << department_1[1].get_sal() * department_1[1].get_hours();
	}
