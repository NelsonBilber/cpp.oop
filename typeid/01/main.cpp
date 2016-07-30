#include <iostream>
#include <typeinfo>

using namespace std;

struct Poly{
	virtual void m() {}
};


struct Normal{
	
};

struct D : public Poly
{
    void m() {}
};

struct N: public Normal{};

int main()
{
    Poly* p = new Poly();
    Normal* n = new Normal();
    D* d = new D();
    N* nn = new N();
    N* nn2 = new N();

    cout << "type id normal   = " << typeid(n).hash_code() << endl;
    cout << "type id poly     = " << typeid(p).hash_code() << endl;
    cout << "type name normal = " << typeid(n).name() << endl;
    cout << "type name poly   = " << typeid(p).name() <<endl;
    cout << "type name D      = " << typeid(d).name() <<endl;
    cout << "type name N      = " << typeid(nn).name() <<endl;
    cout << "type name N'     = " << typeid(nn2).name() <<endl;
    
    return 0;
}
