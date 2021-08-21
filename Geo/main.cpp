/*
1. Реализовать классы:Rectangle и Circle (круг рисуется при помощи функции Ellipse);
2. Добавить в нашу классовую иерархию треугольники;*/
#include <iostream>
#include <Windows.h>
#include <math.h>
using namespace std;
enum color
{
	COLOR = 0x11
};
class rect
{
	double a;
	double b;
public:
	double get_a() { return a; }const
	double get_b() { return b; }const

	void set_a(double value) { a = value; }
	void set_b(double value) { b = value; }

	void area(double a, double b) { cout << a * b; }
	void perimeter(double a, double b) { cout << 2 * (a + b); }
	void print()
	{
		cout
			<< "\na = " << get_a();

		cout << "\nb= " << get_b();

		cout
			<< "\nArea: "; area(a, b);
		cout
			<< "\nPerimeter: "; perimeter(a, b);
	}

	rect(double a, double b)
		{
			this->a = a; this->b = b;
		}

	void draw()
	{
		HWND hwnd = GetConsoleWindow();
 		HDC hdc = GetDC(hwnd);
		HPEN pen = CreatePen(PS_SOLID, 10, color::COLOR);
		HBRUSH bruh = CreateSolidBrush(color::COLOR);
		SelectObject(hdc, pen);
		SelectObject(hdc, bruh);
		Rectangle(hdc, 100, 100, a, b );
		DeleteObject(bruh);
		DeleteObject(pen);
		ReleaseDC(hwnd, hdc);
	}
};
class Circle
{
	double d;
	double r;
	const double pi = 3.14;
public:
	double get_d() { return d; }const
	double get_r() { return r; }const

	void set_d(double value) { d = value; }
	void set_r(double value) { r = value; }

	double area() { return pi * (r * r); }
	void draw()
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN pen = CreatePen(PS_SOLID, 5, color::COLOR);
		SelectObject(hdc, pen);
		Ellipse(hdc, 100, 100, r, d);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	Circle(double r, double d) { this->r = r, this->d = d; }
};
class poly
{
	double a; double b; double c; double height;
public:
	double get_a() { return a; } const
	double get_b() { return b; } const
	double get_c() { return c; } const

	void set_a(double value) { a = value; }
	void set_b(double value) { b = value; }
	void set_c(double value) { c = value; }

	poly(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	};
	//////////////////////////////////////////////
	double perimer() { return a + b + c; }
	double area(double perimeter) 
	{ 
		double hper = perimeter / 2;  //hper = half perimeter
		return sqrt(hper * (hper - a) * (hper - b) * (hper - c));
	}
	double height(double perimeter) 
	{
		double hper = perimeter / 2;  //hper = half perimeter
		height = 2 * sqrt(hper * (hper - a) * (hper - b) * (hper - c));
		return height;
	}
};
void main()
{
	poly poly(10, 10, 10);
	double p = poly.perimer();
	cout << poly.area(p);
}