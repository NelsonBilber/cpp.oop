#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "class A" << endl;
	}

	virtual A* returnType() = 0;
	
	int teste(int b, int c)
	{
		cout << "test two int values" << endl;
		return 0;
	}

	int teste(int b, int c, int j)
	{
		cout << "test three int values" << endl;
		return 0;
	}

	
	int teste (float b, float c)
	{
		cout << "test two float values" << endl;
  		return 0;
	}	
};

class B: public A
{
public:
  	B()
	{
		cout <<"class B"<< endl;
	}
	inline int getId(){return i;}

	B* returnType() override
	{
		cout << "return from derived class" << endl;
		return new B();
	}
	
private:
	int i;
};

 
int main()
{
   	A* a = new B();
	a->returnType();
	a->teste(1,2);
	a->teste(1,3,3);
	a->teste((float)1.0,(float)1.2);
	
	return 0;
}
