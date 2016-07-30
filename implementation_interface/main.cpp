// Example from book: The C++ programming Language

// Technique used in older implementations
// default implemnetation for methods and data
// most of code is implemented using pointers
#include <iostream>

using namespace std;


class lval_box
{
protected:
    int val;
    int low, hight;
    bool changed{false};
    
    void setChanged(bool state) {changed = state;}
    
public:
    lval_box(int ll, int hh):val{ll},low{ll}, hight{hh}{}
    
    virtual void prompt(){ cout <<"base class lval_box"<< endl;}
    
    virtual ~lval_box(){}
};

class lval_slider: public lval_box
{
public:
    lval_slider(int ll, int hh): lval_box(ll, hh) {}
    ~lval_slider(){}
    
    virtual void prompt() {cout << "lval_slider()" << endl; setChanged(true);}
};


void interact(lval_box * lb)
{
    lb->prompt();
}

int main()
{
    
    //use smart pointers
    unique_ptr<lval_box> p1 {new lval_box{0,5}};
    interact(p1.get());
    
    unique_ptr<lval_slider> p2 {new lval_slider{0,5}};
    interact(p2.get());
    
    //p2->setChanged(true);
    
    return 0;
}



