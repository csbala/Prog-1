#include "std_lib_facilities.h"

void print(map<string,int>const& m){
	for(auto& i : m)
		cout << i.first << " " << i.second << endl;
}

void insert(map<string,int>& m){

	string s("");
	int i(0);
	int j(0);

	while(j<10)
	{
		cin >> s >> i;
		m.insert(make_pair(s,i));
		j++;
	}
}

int main(){

	map<string,int> msi;

	cout << "Insert the elements:\n";
	insert(msi);	
	std::cout << "Map elements:\n";
	print(msi);

	msi.erase(msi.begin(),msi.end());

	cout << "\nInsert the new elements:\n";
	insert(msi);
	std::cout << "Map new elements:\n";
	print(msi);

	/*int sum=0;
	for(auto& i : msi)
		sum+=i.second;*/

	int sum = accumulate(msi.begin(),msi.end(), 0 ,[](int i, pair<string,int> map){return i+=map.second;});
	
	cout << "\nSum of the integers:" << sum << endl;

	
	map<int,string> mis;

	for (const auto& a : msi)
       	   mis[a.second] = a.first;

    	cout << '\n';

	for(auto& i : mis)
		cout << i.first << ' ' << i.second << endl;


	return 0;
}
