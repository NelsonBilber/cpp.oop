#include <iostream>

using namespace std;


class Base{
public:
	Base()  { cout << "+ ctor from base classe "<< endl; }
	virtual ~Base() { cout << "- dtor from base classe "<< endl; }
	//NOTE:: object is manipulated throught the interface provided by
	//base class and usually is delete from it. If base destructor is
	//not declared as virtual, the destructor from base class isn't invoked
	virtual void name() = 0;
};

class Derived: public Base {
public:
	Derived():Base()  { cout << "+ ctor from derived classe "<< endl; }
	~Derived () { cout << "- dtor from derived classe "<< endl; }
	virtual void name(){ cout << "class name : Derived" << endl;}
};



int main()
{
	//NOTE::base has an abstract method and can't be instanciated
	//Base* b1 = new Base();
	//delete b1;
	cout << endl;
	Derived* d1 = new Derived();
	d1->name();
	delete d1;

	return 0;
}
