#include "std_lib_facilities.h"

template<typename T>
void print(T& v){
	for(auto i : v){
		cout << i << endl;
	}
}

class Less_than{

double i;

public:
Less_than(double ii) : i(ii) { }
bool operator()(double x) const { return x < i; }

};


int main(){
//1
	vector<double> vd;
	double tmp;

	ifstream in("ch21_drill_3.txt");

	while(in >> tmp)
		vd.push_back(tmp);

//2
	cout << "The elements of vd:\n";
	print(vd);

//3
	vector<int> vi;
	vi.resize(vd.size());

	copy(vd.begin(),vd.end(),vi.begin());

//4
	cout << '\n' << "<double>" << '\t' << "<int>" << '\n';
	for(int i=0;i<vd.size();i++)
	    cout << vd[i] << "\t\t" << vi[i] << '\n';

//5
	double vd_sum = std::accumulate(vd.begin(),vd.end(),0.0);
	cout << "\nSum of the vd: " << vd_sum << endl;

//6
	int vi_sum = std::accumulate(vi.begin(),vi.end(),0);
	double dif = vd_sum - vi_sum;
	cout << "Difference between vi sum and vd sum: " << dif << endl;

//7
	cout << "\nThe elements of the reverse vd:\n";
	reverse(vd.begin(),vd.end());
	print(vd);

//8
	int mean_value = vd_sum / vd.size();
	//középérték = (elemek összege / elemek darabszáma)
	cout << "\nMean value of the elements in vd:" << mean_value << endl;

//9
	vector<double> vd2;
	vd2.resize(vd.size());

	copy_if(vd.begin(),vd.end(),vd2.begin(),Less_than(mean_value));
	
	cout << "\nThe elements of vd2:\n";
	print(vd2);

//10
	sort(vd.begin(),vd.end());
	cout << "\nThe elements of sort vd:\n";
	print(vd);

	return 0;
}	