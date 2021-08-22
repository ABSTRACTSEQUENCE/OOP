#include <iostream>
#include <Windows.h>
class square;
class rectangle;
class shape;
using namespace std;
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
	enum = enumeration (перечисление) набор целочисленных именованных констант. Удобно для перечисления цветов, вариантов case.
	К сожалению, с C++ enum может хранить лишь целочисленные константы и не могут хранить константы других типов, даже символьные
	enum являются типами данных и переменные типа enum могут принимать только одно из перечисленных значений
	*/
	class shape
	{
	protected:
		color Color; // Любую геометрическую фигуру можно нарисовать каким-то определённым цветом
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
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Обработчик окна консоли 
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
		//Обработчик окна
		HWND hwnd = GetConsoleWindow();//Обработчик окна
		//Контекст устройства
		HDC hdc = GetDC(hwnd);//HDC = handler to device content
		//Карандаш и кисть для рисования
		HPEN hpen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));//PS_SOLID сплошная линия, 5 толщина в пикселях, цвет
		// pen рисует контур фигуры
		HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 0));
		//Берем соданные карандаш и кисть
		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);
		//Рисуем квадрат
		Rectangle(hdc, 500, 500, side, side);
		//Освобождаем ресурсы
		DeleteObject(hbrush);
		DeleteObject(hpen);
		ReleaseDC(hwnd, hdc);
		}
	};
class rectangle : public shape
{

};
class triangle : public shape
{
public:
	triangle(color Color) :shape(Color) {};
	~triangle() {};

	virtual double get_area()const = 0;
	virtual double get_height()const = 0;
};
class triangle_eq : public triangle //equirateral
{
	double side;
public:
	double get_side() { return side; } const
		double set_side(double value)
	{
		if (side <= 0) side = 1;
		side = value;
		return side;
	}
	triangle_eq(double side, color Color) : triangle(Color), side(set_side(side)) {};
	~triangle_eq() {};

	double get_area()const
	{
		return get_height() * side;
	};
	double get_height()const
	{
		return sqrt(3) / 2 * side;
	};
	double get_perimeter()const { return side * 3; }
	void draw()const
	{
		HWND hwnd = GetDesktopWindow();
		HDC hdc = GetDC(hwnd);
		HPEN pen = CreatePen(PS_SOLID, 5, Color);
		HBRUSH bruh = CreateSolidBrush(Color);
		SelectObject(hdc, pen); SelectObject(hdc, bruh);
		POINT points[] =
		{
			{200, 200 + side},
			{200 + side, 200 + side},
			{200 + side / 2, 200 + side - get_height()},
		
		};
		Polygon(hdc, points, sizeof(points) / sizeof(POINT));
		DeleteObject(bruh); DeleteObject(pen);
		ReleaseDC(hwnd, hdc);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
};
}//появился в середине
void main()
{
	 geo::triangle_eq tri(130, geo::color::CONSOLE_GREEN);
	std::cout<< tri.get_side() << std::endl;
	tri.draw();
	//	shape Shape(color::CONSOLE_BLUE);
		//	cout << hex << Shape.get_color() << endl;
	/*	square sq(100, color::CONSOLE_RED);
		cout << "Side length: " << sq.get_side() << endl
			<< "Area: " << sq.get_area() << endl
			<< "Perimeter: " << sq.get_perimeter() << endl;
		sq.draw();
		rectangle rect;*/

}

