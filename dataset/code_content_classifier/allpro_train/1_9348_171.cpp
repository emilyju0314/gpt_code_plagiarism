#include<iostream>
#include<algorithm>
using namespace std;
int s[1000], k[10000], n, m, t, p, i, j;
int main() {
	while (true) {
		t = 0; p = 0;
		cin >> n >> m;
		if (n == -1) { break; }
		while (t < m) {
			n++;
			if (n < 2) { goto E; }
			for (i = 2; i*i <= n; i++) {
				if (n%i == 0) {
					goto E;
				}
			}
			s[t] = n;
			t++;
		E:;
		}
		for (i = 0; i < m; i++) { for (j = i; j < m; j++) { k[p] = s[j] + s[i]; p++; } }
		sort(k, k + p);
		cout << k[m - 1] << endl;
	}
	return 0;
}