#include "std_lib_facilities.h"

struct Person{

Person(string name, int age): m_name(name), m_age(age) {
	string problem = ";:'[]*&^%$#@!";
	char c='"';
	problem=problem+c;

	for(auto i : problem){
		for(auto j : name){
			if(i==j){
				error("forbiden character:");}
		}
	}
}

string name() const 
{  return m_name; }

int age() const 
{  return m_age; }

public:
	string m_name;
	int m_age;

};

ostream &operator<<(ostream &op, Person p) {
    op<<p.name()<<' '<< p.age()<<endl;
    return op;
}

istream &operator>>(istream &i, Person &p) {
    string trash_name;
    int trash_age;
    i>>trash_name;
    i>>trash_age;
    p = Person{trash_name, trash_age};

    return i;
}

int main(){

Person p1{"Goofy",63};
cout<<p1;
cin>>p1;
cout<<p1;

	return 0;
}