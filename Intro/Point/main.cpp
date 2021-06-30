#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n---------------"
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define CONSTRUCTOR_CHECK
//#define STRUCT_POINT
//#define CONSTRUCTORS_OVERLOADING
class Point
{
	double x;
	double y;
public:
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	double distance(Point& other)
	{
		//B- this
		//A -other
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt == square root
		return distance;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//constructors
#ifdef CONSTRUCTORS_OVERLOADING
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;

	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single parameter constructor :\t" << this << endl;
	}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Double parameter constructor : \t" << this << endl;
	}
	Point(const Point& other)
	{//shallow copy
		this->x = other.x;
		this->y = other.y;
		cout << "Copy Constructor: \t" << endl;
	}
	~Point()
	{
		cout << "\nDestructor: \t" << this << endl;
	}
	//operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy assignment" << endl;
		return *this;
	}
#endif
};
double distance(const Point& A, Point& B)
	{
		double x_distance = A.get_x() - B.get_x();
		double y_distance = A.get_y() - B.get_y();
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	/*void coordinates(Point A, Point B)  //В этой функции пользователь вбивает координаты точек
	{   ///A
		cout << "A coordinates input..." << endl;
		int a_input_x; int a_input_y;
		cout << "Awaiting X input..." << endl; cin >> a_input_x;
		cout << "Awaiting Y input..." << endl; cin >> a_input_y;
		A.set_x(a_input_x);
		A.set_y(a_input_y);
		///B
		cout << "B coordinates input..." << endl;
		int b_input_x; int b_input_y;
		cout << "Awaiting X input..." << endl; cin >> b_input_x;
		cout << "Awaiting Y input..." << endl; cin >> b_input_y;
		B.set_x(b_input_x);
		B.set_y(b_input_y);
		///
		cout << "A x, y : " << A.get_x() << tab << A.get_y() << endl;
		cout << "B x, y : " << B.get_x() << tab << B.get_y() << endl;
	}*/
	void main()
	{
		setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
		Point A;
		A.x = 2;
		A.y = 3;
		cout << A.x << tab << A.y << endl;
		Point* pA = &A;
		cout << pA->x << tab << pA->y << endl;
		cout << (*pA).x << tab << (*pA).y << endl;
#endif
#ifdef DISTANCE_CHECK 
		Point A;
		A.set_x(2);
		A.set_y(3);
		Point B;
		B.set_x(4);
		B.set_y(5);
		//coordinates(A, B);
		cout << delimeter << endl;
		cout << "Distance from A to B:\t " << A.distance(B) << endl;
		cout << "Distance between A and B:" << distance(A, B) << endl;
		cout << delimeter << endl;
#endif
#ifdef CONSTRUCTOR_CHECK
		Point A;
		Point B = 3;
		Point C(2, 3);
		Point D = C;
		Point E;
		E = C;
		A.print();
		B.print();
		C.print();
		D.print();
		E.print();
#endif
#ifdef ASSIGNMENT_CHECK
		int a, b, c;
		a = b = c = 0;
		cout << a << tab << b << tab << c << endl;
		Point A, B, C;
		cout << "\n---------------------\n";
		A = B = C = Point(4, 5);
		cout << "\n-------------------\n";
		A.print();
		B.print();
		C.print();
#endif
	}
