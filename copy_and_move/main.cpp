// this examples was taken from "The cpp programming language"

#include <iostream>
#include <array>
#include <memory>
#include <algorithm>

using namespace std;

template <class T>
class Matrix
{
    array<int,2> dim;      //two dimensions
    T* elem;               //pointer to dim[0]*dim[1] elements of type T
public:
    Matrix(): dim{{0,0}}, elem { new T[0]}{}

    Matrix(int d1, int d2): dim{{d1,d2}}, elem{ new T[d1*d2] }
    {
        cout<<"matrix constructor"<<endl;
    }

    int size() const { return dim[0]*dim[1]; }

    //copy contructor
    Matrix(const Matrix& m): dim (m.dim), elem(new T [m.size()])
    {
        //dim = m.dim;
        //elem = new T [m.size()];
        uninitialized_copy(m.elem, m.elem+m.size(), elem);
        cout <<"copy constructor "<<endl;
    }

    //copy assignment
    Matrix& operator=(const Matrix& m)
    {
        Matrix tmp {m}; //make a copy (with copy contructor)
        
        //Error on delete because it shares the pointers
        //std::swap(tmp, *this); //swap tmp's representation with *this's
        
        if( dim[0] != m.dim[0] || dim[1] != m.dim[1])
		{
            throw runtime_error("bad size in Matrix = ");
        }
        swap(tmp.dim, dim);
        copy(m.elem, m.elem+m.size(), elem);
        
        cout <<"copy assignment "<<endl;
        return *this;
    }


    //move constructor
    Matrix(Matrix &&a): dim(a.dim), elem(a.elem)
    {
		a.dim = {0,0};
		a.elem = nullptr;
        cout <<"move constructor "<<endl;
    }

    //move assignment
    Matrix& operator=(Matrix &&a)
    {
		swap(dim, a.dim);
		swap(elem, a.elem);
        cout <<"move assigment "<<endl;
        return *this;
    }

	template<class R>
	void swap(R& a,R& b)
    {
		R tmp = std::move(a);
		a = std::move(b);
		b = std::move(tmp);
	}

    ~Matrix()
    {
        delete[] elem;
    }
};

int main()
{
    Matrix<int> matrix (7,10);
    cout << "matrix1 has " << matrix.size() << " elements \n" << endl;

    Matrix<int> matrix2(matrix);
    cout << "matrix2 has " << matrix2.size() << " elements \n" << endl;

	Matrix<int> matrix4 = matrix2 ;
    cout << "matrix4 has " << matrix4.size() << " elements \n" << endl;
	
    Matrix<int> matrix3(7,10);
    matrix3 = matrix2;
    cout << "matrix3 has " << matrix3.size() << " elements \n" << endl;

    return 0;
}
