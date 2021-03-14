#include "std_lib_facilities.h"

class B1{
public:
	virtual void vf() const {cout<<"B1::vf()\n";}
	void f() const {cout<<"B1::f()\n";}
	virtual void pvf(){}
};

class D1 : public B1 {
public:
	void vf() const override {cout<<"D1::vf()\n";}
	void f() const {cout<<"D1::f()\n";}
};

class D2 : public D1 {
public:
	void pvf() override {cout<<"D2:pvf()"<<endl;}

};

class B2{
public:
	virtual void pvf(){}

};

class D21 : public B2{
public:
	string string_datamember="Blase";
	void pvf() override  {cout<<string_datamember<<endl;}

};

class D22 : public B2{
public:
	int int_datamember=63;
	void pvf() override  {cout<<int_datamember<<endl;}

};

void f(B2 &ref){

	ref.pvf();
}

int main(){

B1 b1;
b1.vf();
b1.f();

D1 d1;
d1.vf();
d1.f();

B1& b_reference = d1;
b_reference.vf();
b_reference.f();

D2 d2;
d2.f();
d2.vf();
d2.pvf();

D21 d21;
D22 d22;
f(d21);
f(d22);

	
	return 0;
}