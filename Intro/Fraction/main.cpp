#include <iostream>
using namespace std;
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
	fraction(int integer)
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
		this -> integer = integer;
		this -> numerator = numerator;
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
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
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
	}
}

//#define CONSTRUCTORS_CHECK
//#define OPERATORS
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
	fraction A (10, 7);
	fraction B(4, 1);
	fraction C = A + B;
	cout << endl; C.print();
}