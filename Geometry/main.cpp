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
	virtual double area(double a) { return a * a; }
	virtual double perimeter(double a) { return a + a; }

	double get_a() { return a; }
	void set_a(double value) { a = value; }
	virtual void print()
	{

			cout
			<< "\nArea: " << area(a)
			<< "\nPerimeter: " << perimeter(a)
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

	double area(double a, double b) { return a * b; }
	double perimeter(double a, double b) { return 2 * (a + b); }
	void print()
	{
		square::print();
		cout << "\nb= " << get_b();
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
	square sq(3);
	sq.print();
}