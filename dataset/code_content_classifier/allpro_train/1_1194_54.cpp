#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b, x=0;
	for(int i=0;i<n;i++) {
		cin >> a >> b;
		if(a == b) {
			x++;
		} else {
			x = 0;
		}
		if(x == 3) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
