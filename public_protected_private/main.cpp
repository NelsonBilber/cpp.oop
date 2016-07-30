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

protected:
	int varproteced = 1;
	void methodprotected () const { cout << "protected" << endl;}

private:
	int varprivate = 0;
	void methodprivate() { cout << "private" << endl;}
};

class Circle: public IShape
{
public:

	Circle (Point* p) {
		cout << "create circle " <<endl;
	}

	void rotate (int r ) override {
		cout << "rotate circle" << endl;
	}

	void draw() const
	{
		cout << "draw circle" <<endl;

		//access vars and methos with protected acedd
		cout << "var proteced = " << varproteced << endl;
		methodprotected();

		//access vars and methos with private acedd
		//cout << "var private = " << varprivate << endl;
		//methodprivate();
	}

protected:
    void circle_protected()
    {
        cout <<"circle protected method"<<endl;
    }

private:
    int ip = 100;
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

class A {
public:
    A(){}
protected:
    int protecedA = 1;
private:
    int privateA = 0;
};

class B : public A {
public:
    B(){}
    void test ()
    {
        cout << protecedA << endl;
        //cout << privateA << endl; // ERROR:: private vars
        cout << privateB << endl;
    }
protected:
    int protecedB = 2;
private:
    int privateB = 22;
};

int main()
{
	vector <IShape *> shapes;

	IShape *c = new Circle(new Point());
	IShape *r = new Rectangle(new Point());

	shapes.push_back(c);
	shapes.push_back(r);

	for(int i = 0; i < shapes.size(); ++i) {
		shapes[i]->draw();
	}


	//instances can't access to protected members only public
	//Circle* cc = new Circle(new Point());
	//cc->circle_protected();
	//cc->ip();

	B* b = new B();
	b->test();
	//b->protecedB; // ERROR:: instances can't acess to protected and private access
									// only public access works

	return 0;
}
