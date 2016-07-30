// example from book the c++ programming language

#include <iostream>

using namespace std;

struct Storable
{
	Storable()
		{
			cout << "# ctor --> Storable" << endl;
		}
	virtual void write () = 0;

	int sum ()
	   {
		   int t = 2;
		   return t + 2;
	   }

	virtual ~Storable() {}
};

class Transmitter: public virtual  Storable
{
public:
	Transmitter()
		{
			cout << "ctor --> Transmitter" << endl;
		}
				
	void write() override
		{
			cout << "Transmitter ... " << endl;
		}
};

class Receiver: public virtual  Storable
{
public:
	Receiver()
		{
			cout << "ctor --> Receiver " << endl;
		}
	void write() override
		{
			cout << "Receiver ..." << endl;
		}
};

class Radio: public Receiver, public Transmitter
{
public:
	void write() override
		{
			Transmitter::write();
			Receiver::write();
			cout << "radio info .." << endl;
		}	
};

int main()
{
	/*
	        Base class is builded 2x
			to avoid this use "public virtual" base class
			see example ...
	 */
	
	Radio r;
	r.write();

	return 0;
}
