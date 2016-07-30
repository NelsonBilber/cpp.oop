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

	virtual ~Storable() {}
};

class Transmitter: public Storable
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

class Receiver: public Storable
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
			to avoid this use virtual base class
			see example ...
	 */
	
	Radio r;
	r.write();

	return 0;
}
