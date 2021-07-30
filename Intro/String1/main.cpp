#include <iostream>
using namespace std;
class String
{
	int size;
	char* str;
//public:
	//Constructors
	String()
	{
		str = new char[80]{};
		cout << "Default Constructor: " << this << endl;
	}
	String(const int size)
	{
		set_size(size);
		str = new char[size] {};
		cout << "1 Arg. Constructor: " << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor: " << this << endl;
	}
	//methods
	void print()const
	{
		cout << "String content: " << *str << endl << "String size: " << size << endl;
	}
	String get_size()
	{
		return size;
	}
	String get_str()
	{
		return *str;
	}
	void set_size(int size)
	{
		this->size = size;
	}
	//Operators
};
void main()
{
	setlocale(LC_ALL, "Russian");

	String Str(); // Empty
	Str.print();
	//String str1 = "Hello";
	//cout << str1 << endl;
	//String str2 = "World";
	//cout << str2 << endl;
	//String str3 = str1 + str2;
	//cout << str3 << endl;
}