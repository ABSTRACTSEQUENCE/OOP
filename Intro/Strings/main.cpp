#include<iostream>
#include<string>
using namespace std;
struct String			//���� ��� ���������, ����� ���������� �� ��������� ��� �������������.
{
	//methods
	void print() {cout << this; }
	//constructors
	String()
	{
		const int SIZE = 80;
		this[SIZE];
		cout << "\nDefault Constructor\n";
	}
	~String()
	{
		cout << "\nDesturctor\n";
	}
	String& operator =(const String& other)
	{
		
	}
};
void main()
{
	String str;	//������� ������ ������ �������� 80 ����   DONE
	//String str1 = "Hello";
	/*cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;*/

	/*
	��������, �� ����� ��������� ������� � ��������, ������� ������ ������������
	� ���� ������ �� � ��������� ������ ����� �� �������. 
	*/
	
}