#include<iostream>
using namespace std;
/*
   ��������� �������� �������������� �����: �������, �������������, ����, �����������. ��� ������ ������ 
   ����� ��������� �� ������� � ��������, � ��� �� ������ ������ ����� ����������.
   ������� ������ �������������� �����, ������� �� ����� ������� ������ ������ � ���������� ��.
   ��� �� ����� ������������� ������ ��������� �������, � ������� �� ����� ��� �� �������� � ���������� 
   ���������� ������.
*/
class square
{
protected:
	double a;
public:
	virtual void area(double a) { cout << a * a; }
	virtual void perimeter(double a) { cout << a + a; }

	double get_a() { return a; }
	void set_a(double value) { a = value; }
	virtual void print()
	{

		cout
			<< "\nArea: "; area(a);
		cout
			<< "\nPerimeter: "; perimeter(a);
		cout
			<< "\na = " << get_a();

	}

	square(double a) { this->a = a; cout << "\nSconstructor: " << this; }
	~square() { cout << "\nSdestructor " << this << endl; }
};

class rectangle : public square
{
	double b;
public:
	double get_b() { return b; }
	void set_b(double value) { b = value; }

	void area(double a, double b) { cout << a * b; }
	void perimeter(double a, double b) { cout << 2 * (a + b); }
	void print()
	{
		cout
			<< "\na = " << get_a();

		cout << "\nb= " << get_b();

		cout
			<< "\nArea: "; area(a,b);
		cout
			<< "\nPerimeter: "; perimeter(a,b);
	}
	rectangle(double a, double b):square(a) { set_b(b), set_a(a); cout << "\nRconstructor: " << this; }
	~rectangle() { cout << "\nRDestructor " << this <<  endl; }
};
class triangle : public rectangle
{
	double c;
public:
	double get_c() { return c;}
	void set_c(double value) { c = value; }

	void print()
	{
		rectangle::print();
		cout << "\nc = " << get_c();
	}
};
void main()
{
	rectangle rect(2, 3);
	rect.print();
	//square sq(3);
//	sq.print();
}