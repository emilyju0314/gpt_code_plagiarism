#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	int k; cin >> k;
	int n = 1;
	for (int i = 0; i < k; i++)n *= 2;
	for (int i = 0; i < n; i++) {
		int p = i;
		cout << p << ':';
		for (int j = 0; j < k; j++) {
			if (p % 2 == 1)cout << ' ' << j;
			p /= 2;
		}
		cout << endl;
	}
}
