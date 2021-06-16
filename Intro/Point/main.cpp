#include<iostream>
using namespace std;
#define tab "\t"
class Point
{
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	double distance()
	{
		if (x > y) return x - y;
		else if (y > x) return y - x;
		else if (y == x) return 0;
	}
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	double x;
	double y;

};
double distance(double x, double y);
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
	Point A;
	int input_x; int input_y;
	cout << "Awaiting X input..." << endl; cin >> input_x;
	system("CLS");
	cout << "Awaiting Y input..." << endl; cin >> input_y;
	A.set_x(input_x);
	A.set_y(input_y);
	cout << "X coordinate:" << A.get_x() << tab << "Y coordinate:" << A.get_y() << endl;
	cout << "Distance between X and Y: " << A.distance() << endl;
	cout << "(func) Distance between X and Y: " << distance(A.get_x(), A.get_y());
	
}
double distance(double x, double y)
{
	if (x > y) return x - y;
	else if (y > x) return y - x;
	else if (y == x) return 0;
}