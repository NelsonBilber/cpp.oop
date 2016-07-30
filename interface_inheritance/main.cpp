// Example from book: The C++ programming Language

// should not contain no data
// methods pure virtual
// simple as possiblie ex: ...  no ctor() but virtual dtor()

#include <iostream>

using namespace std;


class lval_box
{
protected:
	virtual void setChanged(bool state) = 0;
public:
    virtual void prompt() = 0;
    virtual ~lval_box(){}
};

class lval_slider: public lval_box
{
protected:
    int val;
    int low, hight;
    bool changed{false};
    
    void setChanged(bool state) {changed = state;}
    
public:
    lval_slider(int ll, int hh) {}
    ~lval_slider(){}
    
    virtual void prompt() {cout << "lval_slider()" << endl;}
};


void interact(lval_box * lb)
{
    lb->prompt();
}

int main()
{
    
    //use smart pointers
    //unique_ptr<lval_box> p1 {new lval_box{0,5}}; // can't allocate abstract objects
    //interact(p1.get());
    
    unique_ptr<lval_slider> p2 {new lval_slider{0,5}};
    interact(p2.get());
    
    //p2->setChanged(true);
    
    return 0;
}

