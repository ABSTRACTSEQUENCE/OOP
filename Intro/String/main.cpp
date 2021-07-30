#include<iostream>
#include<string>
//#define CONSTRUCTORS_CHECK
using namespace std;
class String;
String operator + (const String& left, const String& right);
class String
{
	size_t size; //size_t == unsigned int Размер строки в Байтах
	char* str;	//Указатель на строку в динамич. памяти
public:
	unsigned int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default constructor\t" << this << endl;
	}
	String(const char* str)
	{
		//while (str[size++]);

		this->size = strlen(str) + 1; //+1 потому что -> size хранит размер в байтах, а strlen() считает размер в символах
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1 arg constructor\t" << endl;
	} //Константный указатель на char - Это строковая константа
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "Copy Const\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor\t" << this << endl;
	}
	//methods
	void print()
	{
		cout << "Size\t" << size << endl;
		cout << "Str\t" << str << endl;
	}
	//operators
	String& operator =(const String& other)
	{//0) Проверяем не является ли принятый объект нашим объектом
		if (this == &other) return *this;
		//1)Удаляем старое значение, т.е. освобождаем занимаемую им память
		delete[] this->str;
		//2) Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		return *this;
		cout << "Copy Assignment\t" << endl;
	}
	String& operator+=(String& other)
	{
		return *this = *this + other;
	}
	//Оператор [] (subscript operator) возвращает значение по индексу
	const char& operator[](unsigned int i)const // i = index
	{
		return str[i];
	}
	char& operator[](unsigned int i)
	{
		return str[i];
	}
};
String operator + (const String& left, const String& right)
{//1)Создаём строку в которую поместим результат
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	//String str = 5; //Int-string convertion
	String str(5); // Explicit constructor можно вызвать только так, нельзя вызвать оператором =
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();
	String str2 = str1;
	str2.print();
	String str3;
	str3 = str2;
	str3.print();
#endif
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + " " +  str2;
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
}


