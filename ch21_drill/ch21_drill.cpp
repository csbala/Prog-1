#include "std_lib_facilities.h"

struct Item{

	Item() : name(""), iid(0), value(0.0) {}
	Item(string n, int i, double v) : name(n), iid(i), value(v) {}
	
    //friend ostream& operator<<(ostream& os, Item const& item);
    //friend istream& operator>>(istream& is,Item& item);

//private:
	string name;
	int iid;
	double value;
/*
*/
};

istream& operator>>(istream& is,Item& item){
	string n("");
	int    i(0);
	double v(0.0);

	if(is >> n >> i >> v){
		item = Item{n, i, v};
	}
	return is;
}

ostream& operator<<(ostream& os, Item const& item){
	os<< "\t(" << item.name << ", " << item.iid << ", " << item.value << ")\n";

	return os;
}

template<typename T>
void print(T& v){
	for(auto i : v){
		cout << i;
	}
}

int main(){

	vector<Item> vi;
	list<Item> li;

	fstream f("ch21_drill.txt",  ios_base::in);

	for(Item tmp; f >> tmp;){
		vi.push_back(tmp);
		li.insert(li.end(),tmp);
	}
	

	cout<<"My vector:\n";
	print(vi);

	cout << "Sorted by name: " << "\n";
	sort(vi.begin(), vi.end(), [](Item lhs, Item rhs){return lhs.name < rhs.name; });
	print(vi);

	cout << "Sorted by iid: " << "\n";
	sort(vi.begin(), vi.end(), [](Item lhs, Item rhs){return lhs.iid < rhs.iid; });
	print(vi);

	cout << "Sorted by value: " << "\n";
	sort(vi.begin(), vi.end(), [](Item lhs, Item rhs){return lhs.value < rhs.value; });
	print(vi);


	Item item_1("horse_shoe", 99,   12.34);
	Item item_2("Canon_S400", 9988, 499.95);


	vi.insert(vi.end(),item_1);
	vi.insert(vi.end(),item_2);
	cout<<"After the insert:\n";
	print(vi);


	vi.erase(find_if(vi.begin(),vi.end(),[](Item const& i){return i.name=="Hanma";}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item const& i){return i.name=="Tennma";}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item const& i){return i.iid==4;}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item const& i){return i.iid==99;}));
	cout<<"After the erase:\n";
	print(vi);



	cout<<"My list:\n";
	print(li);

	cout << "Sorted by name: " << "\n";
	li.sort([](Item lhs, Item rhs){return lhs.name < rhs.name; });
	print(li);

	cout << "Sorted by iid: " << "\n";
	li.sort([](Item lhs, Item rhs){return lhs.iid < rhs.iid; });
	print(li);

	cout << "Sorted by value: " << "\n";
	li.sort([](Item lhs, Item rhs){return lhs.value < rhs.value; });
	print(li);

	li.insert(li.end(),item_1);
	li.insert(li.end(),item_2);
	cout<<"After the insert:\n";
	print(li);


	list<Item>::iterator list_it;

    list_it= find_if(li.begin(),li.end(),[](Item const& i){return i.name=="Tamas";});
    li.erase(list_it);
    list_it = find_if(li.begin(),li.end(),[](Item const& i){return i.name=="Fast";});
    li.erase(list_it);
    list_it = find_if(li.begin(),li.end(),[](Item const& i){return i.iid==5;});
    li.erase(list_it);
    list_it = find_if(li.begin(),li.end(),[](Item const& i){return i.iid==1;});
    li.erase(list_it);
	
	cout<<"After the erase:\n";
	print(li);


return 0;

}

