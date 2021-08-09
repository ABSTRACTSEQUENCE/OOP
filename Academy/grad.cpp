#include"grad.h"
	const string& Graduate::get_diploma_theme()const
	{
		return diploma_theme;
	}
	void Graduate::set_diploma_theme(const string& diploma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
	Graduate::Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_theme
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diploma_theme(diploma_theme);
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate::~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methods:
	void Graduate::print()const
	{
		Student::print();
		cout << "Тема дипломного проекта: " << diploma_theme << endl;
	}