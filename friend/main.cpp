// more information at: http://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm 

#include <iostream>

using namespace std;

class B
{
public:
  	friend class A;
	inline int getId(){return i;}
private:
	int i;
};

class A
{
public:
	A(B& b)
	{
		b.i = 12;
		cout << b.i << endl;
	}
};
 
int main()
{
   	B b;
	A a(b);
	
	cout << b.getId() << endl;
	return 0;
}
