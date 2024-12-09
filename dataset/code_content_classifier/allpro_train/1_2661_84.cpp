#include <bits/stdc++.h>

using namespace std;

int a, b, h[100005], ans[100005], ansn;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> a >> b;
		if (h[a] >= h[b]) ans[b] = 1;
		if (h[b] >= h[a]) ans[a] = 1;
	}
	ansn = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) ansn++;
	}
	cout << ansn;
	return 0;
}