# include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 10, mod = 1e9 + 7;
int r[N], c[N];
long long ans = 1, sr, sc;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		r[x] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		c[x] = 1;
	}
	for (int i = n * m - 1; i >= 0; i--) {
		if (!r[i] && !c[i]) {
			if (sr * sc - (n * m - i - 1) <= 0) {
				cout << 0;
				return 0;
			}
			ans = (ans * (sr * sc - (n * m - i - 1))) % mod;
			continue;
		}
		if (!r[i]) {
			if (!sc) {
				cout << 0;
				return 0;
			}
			ans = ans * sc % mod;
			sr++;
			continue;
		}
		if (!c[i]) {
			if (!sr) {
				cout << 0;
				return 0;
			}
			ans = ans * sr % mod;
			sc++;
			continue;
		}
		sr++, sc++;
	}
	cout << ans;
	return 0;
}
