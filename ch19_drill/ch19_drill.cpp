#include "std_lib_facilities.h"


template <typename T >
struct S 
{

	S(T value) : val(value) {}

	T& get();
	const T& get() const;

	S& operator=(const T& elem);

private:
	T val;

};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& elem)
{
	val=elem;
	return *this;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
	 os<<"{ ";
    for (auto i : v)
        os << i << " ";
    os<<'}';

    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    char values;
    is >>values;
    
    for(T val; is >> val;) {
        v.push_back(val);

        is.get(values);
        if(values != ',')
            break;
    }

    return is;
}


int main(){


S<int> int_array {10};
S<double> double_array {2.5};
S<char> char_array {'a'};
S<string> string_array {"Hanma"};
S<vector<int>> vector_int_array {{10,20,30,40,50}};


	/*cout << int_array.val << "\n";
	cout << double_array.val << "\n";
	cout << char_array.val << "\n";
	cout << string_array.val << "\n";
	for ( auto elem : vector_int_array.val ){
		cout << elem << ' ';
	}
	cout << "\n";*/



	cout << int_array.get() << "\n";
	cout << double_array.get() << "\n";
	cout << char_array.get() << "\n";
	cout << string_array.get() << "\n";
	for ( auto elem : vector_int_array.get() ){
		cout << elem << ' ';
	}
	cout << "\n";


	cout << "After Set: \n";
	int_array.operator=(7);
	double_array.operator=(0.1);
	char_array.operator=('b');
	string_array.operator=("Baki");

	cout << int_array.get() << "\n";
	cout << double_array.get() << "\n";
	cout << char_array.get() << "\n";
	cout << string_array.get() << "\n";


    int i;
    cout<<"int:";
	read_val(i);
	S<int> int_array_2 {i};

	double d;
    cout<<"double:";
	read_val(d);
	S<double> double_array_2 {d};

	char c;
    cout<<"char:";
	read_val(c);
	S<char> char_array_2 {c};

	string s;
    cout<<"string:";
	read_val(s);
	S<string> string_array_2 {s};

	vector<int> v;
    cout<<"vector<int>:";
	read_val(v);
	S<vector<int>> vector_int_array_2 {v};

	cout<< "\n";
	cout << int_array_2.get() << "\n";
	cout << double_array_2.get() << "\n";
	cout << char_array_2.get() << "\n";
	cout << string_array_2.get() << "\n";
	cout << vector_int_array_2.get() << "\n";


	return 0;

}