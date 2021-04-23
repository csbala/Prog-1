#include "std_lib_facilities.h"

template <typename T >
void print(const T& v, string s){
 cout << s << ": ";
	for(auto i : v)
		cout << i << " ";
 cout << '\n';
}

template <typename T >
void increase(T& v, int val){
	typename T::iterator it;
 for (it=v.begin(); it != v.end(); it++)
 	 *it+=val;      
}

template<class Iter1, class Iter2>
  Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
  while (f1!=e1) {
    *f2 = *f1;
    ++f2; ++f1;
  }
  return f2;
}



int main(){

const int array_size=10;

int array_1[array_size] = {0,1,2,3,4,5,6,7,8,9};
vector<int> vector_1 {0,1,2,3,4,5,6,7,8,9};
list<int> lst_1 {0,1,2,3,4,5,6,7,8,9};

int array_2[array_size];

for(int i=0; i<array_size; i++){
	array_2[i]=array_1[i];
}

vector<int> vector_2 = vector_1;
list<int> lst_2 = lst_1;

print(array_1, "array_1");
print(vector_1, "vector_1");
print(lst_1, "list_1");
print(array_2, "array_2");
print(vector_2, "vector_2");
print(lst_2, "list_2");

//increase all the elements of array with 2
for(int i=0;i<array_size;i++){
	array_2[i]+=2;
}

increase(vector_2, 3);
increase(lst_2, 5);


cout << "After the increasing:\n";

print(array_2, "array_2");
print(vector_2, "vector_2");
print(lst_2, "list_2");


int array_3[array_size];
vector<int> vector_3 (array_size); //le kell neki foglalni a helyet előre, mert anélkül nem tudna hova másolni

cout << "array_2-->vector_3:\n";
my_copy(array_2, array_2+array_size, vector_3.begin());
print(vector_3, "vector_3");

cout << "lst_2-->array_3 :\n";
my_copy(lst_2.begin(), lst_2.end(), array_3);
print(array_3, "array_3");



vector<int>::iterator v_it;

v_it = find (vector_3.begin(), vector_3.end(), 5);
if (v_it != vector_3.end())
    cout << "In the vector, " << *v_it << " was found at: " << distance(vector_3.begin(), v_it) << " index." << '\n'; //v_it - vector_3.begin() ugyan az mint: distance(vector_3.begin(), v_it)
else
    cout << "Element not found in my vector\n";


list<int>::iterator l_it;

l_it = find(lst_2.begin(), lst_2.end(), 27);
if(l_it != lst_2.end())
    cout << "In the list, " << *l_it << " was found at: " << distance(lst_2.begin(), l_it) << " index." << '\n';
else
    cout << "Element not found in my list\n";



return 0;
}