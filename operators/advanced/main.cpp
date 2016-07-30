//example from the book "The c++ programming language"
//Bjarne Stroustroup

//http://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm

#include <iostream>
#include <vector>

using namespace std;

struct Assoc 
{
	vector< pair <string, int> > vec;

	int y;

	//overload operator []
    int& operator[](const string& s) 
	{
		for(auto x : vec)
		{
			if( s == x.first)
		    {
				y = x.second;
				return y;   
		    }
    	}
	
  		vec.push_back({s, 0});
	
	    return vec.back().second;
	}
};


struct Add
{
	int x = 10;

	void operator()(int i)
	{
		x+=i;
	}
};

class Distance
{
private:
	int feet;             // 0 to infinite
	int inches;           // 0 to 12
public:
	// required constructors
	Distance()
    {
		feet = 0;
		inches = 0;
	}
	
    Distance(int f, int i)
    {
		feet = f;
		inches = i;
	}
	// overload function call
	Distance operator()(int a, int b, int c)
    {
        Distance D;
        // just put random calculation
        D.feet = a + c + 10;
        D.inches = b + c + 100 ;
        return D;
    }
	// method to display distance
	void displayDistance()
    {
        cout << "F: " << feet <<  " I:" <<  inches << endl;
    }

};
int main()
{
	Assoc values;
	string buf;
	
	while (cin>>buf)
		++values[buf];

	for(auto x: values.vec)
		cout << '{' << x.first << ',' << x.second << "}\n";

	vector<int> v = {1,2,3};

	Add a= std::for_each(v.begin(), v.end(), Add());
	    
	for( auto x : v)
		cout << x << endl;



	Distance D1(11, 10), D2;

	cout << "First Distance : ";
	D1.displayDistance();

	D2 = D1(10, 10, 10); // invoke operator()
	cout << "Second Distance :";
	D2.displayDistance();

	
    return 0;
}
