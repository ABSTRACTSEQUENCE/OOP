#pragma once
#include"student.h"
class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const;
	void set_diploma_theme(const string& diploma_theme);
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_theme
	);
	~Graduate();

	//			Methods:
	void print()const;
};