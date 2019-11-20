// virtual2 by Mark Whitty to show the use of the following C++ constructs:
//  - pure virtual functions
//  - implementing pure virtual functions in the base class
//  - VTABLES
//  - interfaces

#include <iostream>

using namespace std;

class A
{
protected:
	double a;
public:
	A()
	{
		cout << "An object of type A was created " << endl;
	}
	//Try one of these three lines at a time and inspect the output
	virtual void Draw() = 0;//body cannot be defined/body definition ignored (pure function)
	//virtual void Draw();
	//void Draw();

	// Try one of the two lines below at a time and inspect the output in detail
	//virtual ~A();
	~A();
	// The virtual destructor will force the resources to be destroyed in a proper order
	// when you delete a base class pointer pointing to a derived class object.
};
void A::Draw()
{
	std::cout << "An object of type A is drawn " << endl;
}


A::~A()
{
	cout << "An object of type A is destroyed " << endl;
}

class B: public A
{
protected:
	double b;
public:
	B()
	{
		cout << "An object of type B was created" << endl;
	}
	//void Draw();
	~B();
};

/*void B::Draw()
{
	cout << "An object of type B is drawn " << endl;
}*/

B::~B()
{
	cout << "An object of type B is destroyed " << endl;
}


class C : public B
{
protected:
	double c;
public:
	C()
	{
		cout << "An object of type C was created " << endl;
	}
	void Draw();
	double getC() {
		return c;
	}
	~C();
};

void C::Draw()
{
	cout << "An object of type C is drawn " << endl;
}

C::~C()
{
	cout << "An object of type C is destroyed " << endl;
}


int main()
{
	A *APtr0 = nullptr;  // Change the type of this pointer to see different effects

// Try one of these lines at a time and inspect the output
	APtr0 = new C;
	if(APtr0 == nullptr)
	{
		cout << "Memory allocation failed " << endl;
		return -1;
	}

	//Engine
	APtr0->Draw();
	//std::cout << "objectC data " << objectC.getC()  <<  " " << APtr0->getC() << std::endl;
	if(APtr0 != nullptr)
		delete APtr0;

	//std::cin.get();


	return 0;
}
