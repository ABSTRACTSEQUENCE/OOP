#include <iostream>
#include"random.h"
using namespace std;
const string random(bool value) //true - fname		false - sname
{
	if (value)
	{
		const string fnames[5]{ "Ivan", "John", "Adam","Pavel", "Josh" };
		int random = rand() % 5;
		return fnames[random];
	}
	else if (!value)
	{
		const string lnames[5]{ "Petrov", "Kuzmin", "Marston", "Ducks", "Brown" };
		int random = rand() % 5;
		return lnames[random];
	}
};
const int srandom(bool value) //true = hour, false = month	
{
	int wage;
	if (value)			wage = 100 + rand() % 500; //hour
	else if (!value)	wage = 10000 + rand() % 50000; //month
	return wage;
}
const unsigned int hrandom()
{
	return 70 + rand() % 200; // hours per month   почему-то рандом выходит за рамки максимального значения, поэтому я поставил 70 чтоб максимум был примерно 200-300
}	