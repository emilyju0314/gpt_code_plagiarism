#include<iostream>
#include<algorithm>
using namespace std;
int a[200010], b[200010];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		if (a[i] >= b[n / 2])cout << b[n / 2 - 1] << endl;
		else cout << b[n / 2] << endl;
	}
	return 0;
}