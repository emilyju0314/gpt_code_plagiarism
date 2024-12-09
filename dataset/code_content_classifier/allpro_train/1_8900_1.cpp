#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<int, int> m;
	while(n--){
		int a;
		cin >> a;
		m[a]++;
	}
	cout << m.size() - !(m.size() & 1) << endl;
}