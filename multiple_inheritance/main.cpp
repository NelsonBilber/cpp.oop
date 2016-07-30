// example from book the c++ programming language

#include <iostream>

using namespace std;

class Satellite
{
public:
	virtual void debug_info()
	{
		cout << "stellite ..." << endl;
	}
};

class Displayed
{
public:
	virtual void debug_info()
	{
		cout << "displayed ... " << endl;
	}

};

class Both: public Satellite, public Displayed
{
public:
	void drift()
	{
		cout << "drift ...";
	}
};

void f(Both b)
{
	//name clash
	b.Displayed::debug_info();
}
 
int main()
{
	Both b;
	f(b);
	return 0;
}
