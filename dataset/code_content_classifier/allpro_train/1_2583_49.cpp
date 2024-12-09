#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int n, m;
int h, t, q[N];
char S[N], T[N];

int main() {
	cin >> n;
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	int flag = 1;
	for (int i = 1; i <= n; ++i) {
		if (S[i] != T[i]) flag = 0;
	}
	if (flag) return 0 * puts("0");
	int pos = n, ans = 0;
	h = 1, t = 0;
	for (int i = n; i >= 1; --i) {
		if (T[i] == T[i - 1]) continue;
		pos = min(pos, i);
		while (pos && T[i] != S[pos]) --pos;
		if (!pos) return 0 * puts("-1");
		while (h <= t && q[h] - (t - h + 1) + 1 > i) ++h;
		q[++t] = pos;
		if (i != pos) ans = max(ans, t - h + 1);
	}
	cout << ans + 1 << endl;
	return 0;
}
