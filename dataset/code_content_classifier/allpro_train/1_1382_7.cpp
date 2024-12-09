#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
string s, t; ull p[4009], h1[4009][4009], h2[4009][4009];
int main() {
	cin >> s >> t; p[0] = 1;
	for (int i = 0; i < 4005; i++) p[i + 1] = p[i] * 10007;
	int n = s.size(), m = t.size();
	for (int i = 0; i < n; i++) {
		ull h = 0;
		for (int j = i + 1; j <= n; j++) {
			h += p[s[j - 1] - 97];
			h1[j - i][i] = h;
		}
	}
	for (int i = 0; i < m; i++) {
		ull h = 0;
		for (int j = i + 1; j <= m; j++) {
			h += p[t[j - 1] - 97];
			h2[j - i][i] = h;
		}
	}
	int z = min(n, m);
	for (int i = 1; i <= z; i++) sort(h1[i], h1[i] + n - i + 1);
	for (int i = 1; i <= z; i++) sort(h2[i], h2[i] + m - i + 1);
	int ret = 0;
	for (int i = 1; i <= z; i++) {
		for (int j = 0; j < n - i + 1; j++) {
			int ptr = lower_bound(h2[i], h2[i] + m - i + 1, h1[i][j]) - h2[i];
			if (h2[i][ptr] == h1[i][j]) ret = max(ret, i);
		}
	}
	cout << ret << endl;
	return 0;
}