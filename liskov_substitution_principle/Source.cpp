//Liskov's Substitution Principle(LSP)
#include<iostream>
using namespace std;

class Rectangle
{
protected:
	int m_width = 0;
	int m_height = 0;
public:
	virtual void set_width(int width) { m_width = width; } 
	virtual void set_height(int height) { m_height = height; }
	virtual int area() { return m_height * m_width; } //if not virtual this base area wil be called not derived
};

class Square :public Rectangle
{
public:
	void set_width(int width) { m_width = m_height= width; }
	void set_height(int height) { m_width = m_height = height; }
	int area() { return m_width * m_height; }
};

void CalcPoly(Rectangle& obj)
{
	obj.set_height(20);
	obj.set_width(30);

	cout<<obj.area();
}

int main()
{
	Square sq;

	CalcPoly(sq); //Here correct results will come for both base and derived objects

	return 0;
}
