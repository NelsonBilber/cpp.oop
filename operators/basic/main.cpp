#include <iostream>

using namespace std;


class Thing
{
public:
	Thing(int id):
		id_(id)
	{
		cout<<"ctor"<<endl;
	}

	Thing operator+(const Thing& t1)
	{
		cout<< "operator+"<<endl;
		int res = id_ + t1.id_;
		return Thing(res);
	}

	Thing& operator+=(const Thing& t1)
	{
		cout<< "operator+="<<endl;

		id_ += t1.getId();
		
		return *this;
	}

	friend ostream &operator<<(ostream& out, const Thing& t)
	{
		out << "\n----------------------" << endl;
		out << " id value = " << t.getId() << endl;
		out << "----------------------" << endl;
		return out;
	}

	inline int getId() const { return id_;}
private:
	int id_;
};



int main()
{
	Thing one(1);
	Thing four(4);
	Thing res = one + four;

	cout << res <<endl;
	res += four;
	cout << res <<endl;

	return 0;
}
