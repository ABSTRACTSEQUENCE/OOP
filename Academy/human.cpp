#include "human.h"

	const string& Human::get_last_name()const
	{
		return last_name;
	}
	const string& Human::get_first_name()const
	{
		return first_name;
	}
	unsigned int Human::get_age()const
	{
		return age;
	}
	void Human::set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void Human::set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void Human::set_age(unsigned int age)
	{
		this->age = age;
	}

	//				Constructors
	Human::Human(const string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	Human::~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	void Human::print()const
	{
		cout << last_name << " " << first_name << ", " << age;
		print_year_suffix(age);
		cout << endl;
	}
	void Human::print_year_suffix(unsigned int age)const
	{
		if (age % 20 >= 5 && age % 20 <= 20)cout << " лет";
		else if (age % 10 >= 5 || age % 10 == 0)cout << " лет";
		else if (age % 10 > 1 && age % 10 < 5) cout << " года";
		else cout << " год";
	}