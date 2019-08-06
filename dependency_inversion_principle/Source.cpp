//Dependency Inversion Principle
#include<iostream>
#include<string>

using namespace std;

//bad example
class Joint {
public:
	void Draw() {};
};

class Memeber;
class GraphicModeller {
	Joint *m_j;
	Member *m_m; //All relevent code should be added 
public:
	void SetDrawObject(Joint* j)
	{
		m_j = j;
	}

	void SetDrawObject(Member* m)
	{
		m_m = m;
	}
	void Draw()
	{
		m_j->Draw();
		m_m->Draw();
	}
};

class Member {
public:
	void Draw() {};
};

//Good Example 

class GraphicObject {
public:
	virtual void Draw() = 0;
};

class Joint : GraphicObject {
public:
	void Draw() {};
};

class Memeber;
class GraphicModeller  {
	GraphicObject* m_o;
public:
	void SetDrawObject(GraphicObject* o)
	{
		m_o = o;
	}


	void Draw()
	{
		m_o->Draw();

	}
};

class Member :public GraphicObject{
public:
	void Draw() {};
};