//use visitor instead of double dispatch

#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

class Visitor;
class Shape;
class Circle;
class Triangle;

class Visitor
{
public:
	virtual bool intersect(const Shape&) const = 0;
	virtual bool intersect(const Circle&) const = 0;
	virtual bool intersect(const Triangle&) const = 0;
};

class Shape : public Visitor
{
public:
};

class Circle: public Shape, public Visitor
{
public:
	virtual bool intersect(const Shape&) const {return true; }
	virtual bool intersect(const Circle&) const {return true;}
	virtual bool intersect(const Triangle&) const {return true;}
};

class Triangle: public Shape, public Visitor
{
public:
	virtual bool intersect(const Shape&) const {return true; }
	virtual bool intersect(const Circle&) const {return true;}
	virtual bool intersect(const Triangle&) const {return true;}

};

void test(Triangle& t, Circle& c)
{
	vector<pair <Shape*, Shape*> > vs { {&t, &t}, {&t,&c}, {&c, &c}};

	for(auto p : vs)
	{
		if(p.first->intersect(*p.second))
		{
			cout << typeid(p.first).name() <<" intersect with "<< typeid(p.second).name() << endl;
		}
	}
}

int main()
{
    Triangle t;
    Circle c;
    test(t, c);
    return 0;
}
