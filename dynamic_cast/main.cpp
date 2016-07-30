// more information at: http://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm 

#include <iostream>

using namespace std;

struct Base {
	void print() { std::cout <<"Base"<<std::endl;}
};

struct Derived: Base {
	void print() { std::cout <<"Derived"<<std::endl;}
	virtual void v() {}; // need to be virtual to cross cast
};

struct Cross: public Base {
	void print() { std::cout<<"Cross"<<std::endl;}
	//virtual void  v() {};
};

class CBase{
	virtual void poly() {};  // must be polymorphic to use runtime-checked dynamic_check_and_cast<

};
 
int main()
{
	cout << "# upcast pointers <static_cast>" << endl;
    Derived* d = new Derived();
	Base* b = static_cast<Base *>(d);
	b->print();
	cout << "# upcast wothout pointers <static_cast>" << endl;
	Derived dref;
	Base bref = static_cast<Base>(dref);
	bref.print();
//
	cout << "# upcast pointers <dynamic_cast>" << endl;
    Derived* dd = new Derived();
	Base* bb = dynamic_cast<Base *>(dd);
	bb->print();
	cout << "# upcast references <static_cast>" << endl;
	cout << "Error::dynamic_cast only can be used with pointers" <<endl;
	/*Derived ddref;
	Base bbref = dynamic_cast<Base>(ddref);
	bbref.print();*/
//
	cout << "# downcast pointers <static_cast>" << endl;
	Base* bdwn = new Base();
	Derived* ddwn = static_cast<Derived*>(bdwn);
	ddwn->print();

	cout << "# downcast without pointers <static_cast>" << endl;	
	cout << "Error:: static_cast only can be used with pointers" <<endl;
	/*Base bdwnref;
	Derived ddwnref = static_cast<Derived>(bdwnref);
	ddwn->print();*/
//
	cout << "# downcast pointers <dynamic_cast>" << endl;
	cout << "Error:: dynamic_cast error because base type is not polymorphic type" <<endl;
	Base* bbdwn = new Base();
	//Derived* dddwn = dynamic_cast<Derived*>(bbdwn);
	//dddwn->print();

	cout << "# cross  <dynamic_cast>" << endl;
	Derived* dcross = new Derived();
	Cross* cross = dynamic_cast<Cross*>(dcross);
	cross->print();

	
	return 0;
}
