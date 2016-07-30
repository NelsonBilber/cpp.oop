// use visitors instead

#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

class Circle;
class Triangle;

class Shape{
public:
	virtual bool intersect(const Shape&) const = 0;
	virtual bool intersect(const Circle&) const = 0;
	virtual bool intersect(const Triangle&) const = 0;
};

class Circle: public Shape{
public:
	bool intersect(const Shape&) const override { return true;}
	bool intersect(const Circle&) const override { return true;}
	bool intersect(const Triangle&) const override { return true;}
};

class Triangle: public Shape{
public:
	bool intersect(const Shape&) const override { return true;}
	bool intersect(const Circle&) const override { return true;}
	bool intersect(const Triangle&) const override { return true;}
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
