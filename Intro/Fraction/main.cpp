#define _CRT_SECURE_NO_WARNINGS	//strtok
#include <iostream>
using namespace std;
class fraction;
fraction operator * (fraction left, fraction right);
class fraction
{
	int integer; //Целое
	int numerator; //Числитель
	int denominator;//Знаменатель
public:
	//get///////////////////////////
	int get_int()const
	{
		return integer;
	}
	int get_num()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	//set///////////////////////////
	void set_int(int integer)
	{
		this->integer = integer;
	}
	void set_num(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//Constructors//////////////////
	fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default:\t" << this << endl;
	}
	explicit fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}
	fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2 arg Constructor:\t" << this << endl;
	}
	fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "3 arg Constructor:\t" << this << endl;
	}
	fraction(const fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator =	decimal *= denominator;
		reduce();
	}

	~fraction()
	{
		cout << "Destructor: \t" << this << endl;
	}
	//Operators/////////////////////
	fraction& operator = (const fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Assignment: \t" << this << endl;
		return *this;
	}
	fraction& operator *= (const fraction& other)
	{
		return *this = *this * other;   ////???????
	}
	fraction& operator++() //Префикс
	{
		integer++;
		return *this;
	}
	fraction operator++(int) //Постфикс
	{
		fraction old = *this;
		integer++;
		return old;
	}
	fraction& operator--()
	{
		integer--;
		return *this;
	}
	///////
	operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	//Methods///////////////////////
	void print()const
	{
		if (integer) cout << integer;
		if (integer && numerator) cout << "(";
		if (numerator) cout << numerator << "/" << denominator;
		if (integer && numerator) cout << ")";
		if (integer == 0 && numerator == 0) cout << 0;
		cout << endl;
	}
	fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	fraction inverted()// Обращает дробь ( меняет числитель и знаменатель )
	{
		to_improper();
		/*int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;*/
		return fraction(denominator, numerator);
	}
	fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
			{
				rest = more % less;
				more = less;
				less = rest;
		}while (rest);
		int GCD = more; //Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};
fraction operator* (fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	/*fraction result;
	result.set_num(left.get_num() * right.get_num());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	*/
	/*fraction result
	(
		left.get_num() * right.get_denominator(),
		left.get_denominator() * right.get_denominator()
	);
	return result;*/
	return fraction
	(
		left.get_num() * right.get_num(),
		left.get_denominator() * right.get_denominator()
	);
}
fraction operator+ (fraction left, fraction right)
{
	left.to_improper();
	right.to_improper();
	return fraction
	(
		left.get_num() * right.get_denominator() + right.get_num() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
	/* CRINGE ALERT!!!!
	
	if (left.get_denominator() == right.get_denominator()) 
	{
		return fraction(
			left.get_num() + right.get_num(),
			left.get_denominator() 						   
		);
	}
	else
	{
		int nok = 1;
		int multiL;
		int multiR;
		for (nok; true; nok++)
		{
			if (nok % left.get_denominator() == 0 && nok % right.get_denominator()  == 0)
			{
				multiL = nok / left.get_denominator();
				multiR = nok / right.get_denominator();
				left.set_denominator(nok); right.set_denominator(nok);
				left.set_num(multiL * left.get_num());
				right.set_num(multiR * right.get_num());
				break;
			}
		}
		return left + right;
	}*/

}
fraction operator/ (fraction left, fraction right)
{
	/*left.to_improper();
	right.to_improper();
	fraction result
	(
		left.get_num() * right.get_denominator(),
		left.get_denominator() * right.get_num()
		return result;*/
	/*fraction result = left * right.inverted();
	return result;*/
	return left * right.inverted();
}
bool operator== (const fraction& left, const fraction& right)
{
	return (double)left == (double)right;
	//return (left.get_num() * right.get_denominator() == right.get_num() * left.get_denominator());
}
bool operator!=(const fraction& left, const fraction& right)
{
	return !(left == right);
}
bool operator > (const fraction& left, const fraction& right)
{
	return (double)left > (double)right;
}
bool operator < (const fraction& left, const fraction& right)
{
	return (double)left < (double)right;
}
bool operator >= (const fraction& left, const fraction& right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool operator <= (const fraction& left, const fraction& right)
{
	return left < right || left == right;
}
ostream& operator<<(ostream& os, const fraction& obj)
{
	if (obj.get_int()) os << obj.get_int();
	if (obj.get_int() && obj.get_num()) os << "(";
	if (obj.get_num()) os << obj.get_num() << "/" << obj.get_denominator();
	if (obj.get_int() && obj.get_num()) os << ")";
	if (obj.get_int() == 0 && obj.get_num() == 0) os << 0;
	os << endl;
	return os;
}
istream& operator>>(istream& is, fraction& obj)
{
	/*int integer, num, denom;
	is >> integer >> num >> denom;
	obj.set_int(integer);
	obj.set_num(num);
	obj.set_denominator(denom);
	return is;*/
	const int n = 32;
	char buffer[n] = {};
	char delimeters[] = "(/)  +";
	char* number[5] = {};
	cin.getline(buffer, n);	
	int i = 0;
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters), i++)
		number[i] = pch;
	switch (i)
	{
	case 1:obj.set_int(atoi(number[0])); break;
	case 2: 
		obj.set_num(atoi(number[0]));
		obj.set_denominator(atoi(number[1])); 
		break;
	case 3: 
		obj.set_int(atoi(number[0]));
		obj.set_num(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
		break;
	default: cout << "Error: " << endl;
	}
	return is;

}
//#define CONSTRUCTORS_CHECK
//#define OPERATORS
//#define ARITHMETICS
//#define TYPE_CONV
//#define COMP_OPERATORS
//#define OUTPUT_CHECK
//#define INPUT_CHECK
#define	HW
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	fraction A; // Default constructor
	A.print();
	fraction B = 3;
	B.print(); //Single argument
	fraction C(3, 4);
	C.print();
	fraction D(2, 3, 4);
	D.print();
	fraction E = D;
	E.print();
	fraction F;
	F = E;
	F.print();
#endif
#ifdef OPERATORS
	fraction A(2, 3, 4);
	fraction B(3, 4, 5);
	fraction C = A * B;
	C.print();
	/*A.print();
	A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/
	for (fraction i(1, 4); i.get_int() < 10; ++i)
	{
		i.print();
	} 
#endif
#ifdef ARITHMETICS
	fraction A (10, 7);
	fraction B(4, 1);
	//fraction C = A + B;
	(A + B).print();
	//cout << endl; C.print();
#endif
	/*fraction A(2, 3, 4);
	fraction B(3, 4, 5);
	//A *= B;
	A.print();
	(A * B).print();*/
#ifdef TYPE_CONV
	int a = 2;
	fraction A = (fraction)5;
	A.print();
#endif
#ifdef HW
	//1
	fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;
	//2
	double b = 2.75;
	fraction B = (fraction)b;
	B.print();
	//Надо чтоб работало
#endif
	/*fraction A(5, 5);
	fraction B(6, 8);
	A.print();*/
#ifdef COMP_OPERATORS
	fraction A(1, 2);
	fraction B(3,4);
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
#endif
#ifdef OUTPUT_CHECK
	fraction A(1, 2);
	cout << A << endl;
	fraction B(5);
	cout << B << endl;
	fraction C(1, 2);
	cout << C << endl;
	fraction D(2, 3, 4);
	cout << D << endl;
#endif
#ifdef INPUT_CHECK
	fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << "\n Вы ввели: " << A << endl;
	cout << "Сокращённая дробь: " << A.reduce();
#endif
}