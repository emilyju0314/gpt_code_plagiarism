#include <bits/stdc++.h>
using namespace std;

map<int, char> ans;

const int N = 1100;

int n, a, b, q;

int x[N], y[N], h[N];
char c[N][10];

int get(int pos) {
	while (1) {
		int now = upper_bound(y, y + b + 1, pos) - y - 1;
		if (now == 0 || h[now] == 0) return pos;
		int per = y[now] - h[now];
		pos -= ((pos - y[now]) / per + 1) * per;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> a >> b >> q;
	for (int i = 1; i <= a; i++) cin >> x[i] >> c[i];
	y[0] = 1, y[b + 1] = n + 1;
	for (int i = 1; i <= b; i++) cin >> y[i] >> h[i];
	for (int i = 1; i <= a; i++) {
		ans[get(x[i])] = c[i][0];
	}
	for (int i = 1; i <= q; i++) {
		int z; cin >> z; 
//		cerr << z << endl;
		z = get(z);
//		cerr << z << endl;
		if (!ans.count(z)) cout << "?";
		else cout << ans[z];
	}
	cout << endl;
	return 0;
}

