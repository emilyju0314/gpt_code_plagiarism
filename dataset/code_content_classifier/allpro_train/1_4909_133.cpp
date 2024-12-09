#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, k, c; string s;
	cin >> n >> k >> c >> s;
	int* l = new int[k];
	int* r = new int[k];
	for (int i = 0,ki=0; i < n; i++) {
		if (s[i] == 'o') {
			l[ki++] = i; i += c;
			if (ki == k) break;
		}
	}
	for (int i = n-1,ki=k-1; i >= 0; i--) {
		if (s[i] == 'o') {
			r[ki--] = i; i -= c;
			if (ki == -1) break;
		}
	}
	for (int x = 0; x < k; x++) {
		if (l[x] == r[x]) cout << l[x] + 1 << endl;
	}
	return 0;
}
