#include <iostream>
#include <vector>

using namespace std;

class Point
{};

class IShape
{
public:
	virtual void rotate(int) = 0;
	virtual void draw() const = 0;

	virtual ~IShape(){}
};

class Circle: public IShape
{
public:

	Circle (Point* p){
		cout << "create circle " <<endl;
	}
	
	void rotate (int r ) override {
		cout << "rotate circle" << endl;
	}

	void draw() const {
		cout << "draw circle" <<endl;
	}
};

class Rectangle: public IShape
{
public:

	Rectangle (Point* p){
		cout << "create rectangle " <<endl;
	}
	
	void rotate (int r ) override {
		cout << "rotate rectangle" << endl;
	}

	void draw() const {
		cout << "draw rectangle" <<endl;
	}
};


int main()
{
	vector <IShape *> shapes;
	
	IShape *c = new Circle(new Point());
	IShape *r = new Rectangle(new Point());

	shapes.push_back(c);
	shapes.push_back(r);

	for(int i = 0; i < shapes.size(); ++i){
		shapes[i]->draw();
	}
	
	
	return 0;
}
