#include <iostream>

using namespace std;

int main(){
	int n, m, r;
	cin >> n >> m;
	for(r = m / n; m % r; r--);
	cout << r << endl;
	return 0;
}
