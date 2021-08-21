#include <iostream>
#include <Windows.h>
class square;
class rectangle;
class shape;
namespace geo
{
	enum color
	{// 0x = hexadecimal
	//	0xAF A = bg color, F = font color
		CONSOLE_DEFAULT = 0x07,
		CONSOLE_RED = 0xcc,
		CONSOLE_GREEN = 0xaa,
		CONSOLE_BLUE = 0x99,
	};
	/*
	enum = enumeration (������������) ����� ������������� ����������� ��������. ������ ��� ������������ ������, ��������� case.
	� ���������, � C++ enum ����� ������� ���� ������������� ��������� � �� ����� ������� ��������� ������ �����, ���� ����������
	enum �������� ������ ������ � ���������� ���� enum ����� ��������� ������ ���� �� ������������� ��������
	*/
	class shape
	{
	protected:
		color Color; // ����� �������������� ������ ����� ���������� �����-�� ����������� ������
	public:
		color get_color()const
		{
			return Color;
		}
		void set_color(color value) { Color = value; }
		shape(color Color = color::CONSOLE_DEFAULT) : Color(Color) {}
		virtual ~shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
	};
	class square : public shape
	{
		double side;
	public:
		double get_side()const { return side; }
		void set_side(double value) { if (side <= 0) side = 1; side = value; }

		square(double side, color Color) :shape(Color) { set_side(side); cout << "\nSconstructor: " << this << endl; }
		~square() { cout << "\nDestructor: " << this << endl; }

		double get_area()const { return side * side; }
		double get_perimeter()const { return side * 4; }
		void draw()const
		{
			//#define simple_draw
#ifdef simple_draw
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //���������� ���� ������� 
			SetConsoleTextAttribute(hConsole, get_color());
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, color::CONSOLE_DEFAULT);
		}
#endif
		//���������� ����
		HWND hwnd = GetConsoleWindow();//���������� ����
		//�������� ����������
		HDC hdc = GetDC(hwnd);//HDC = handler to device content
		//�������� � ����� ��� ���������
		HPEN hpen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));//PS_SOLID �������� �����, 5 ������� � ��������, ����
		// pen ������ ������ ������
		HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 0));
		//����� �������� �������� � �����
		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);
		//������ �������
		Rectangle(hdc, 500, 500, side, side);
		//����������� �������
		DeleteObject(hbrush);
		DeleteObject(hpen);
		ReleaseDC(hwnd, hdc);
		}
	};
class rectangle : public shape
{

};
}
void main()
{
	//	shape Shape(color::CONSOLE_BLUE);
	//	cout << hex << Shape.get_color() << endl;
	square sq(100, color::CONSOLE_RED);
	cout << "Side length: " << sq.get_side() << endl
		<< "Area: " << sq.get_area() << endl
		<< "Perimeter: " << sq.get_perimeter() << endl;
	sq.draw();
	rectangle rect;

}
