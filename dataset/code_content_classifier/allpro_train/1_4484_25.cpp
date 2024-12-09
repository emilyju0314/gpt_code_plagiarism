#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 998244353;

int res;
int f[N], g[N];
int prd[N * 3], inv[N * 3];

int C(int n, int k) {
	if (k < 0) return n < 0;
	return 1LL * prd[n] * inv[n - k] % mod * inv[k] % mod; 
}

int pw(int x, int y) {
	if (!y) return 1;
	int ret = pw(x, y >> 1); ret = 1LL * ret * ret % mod;
	if (y & 1) ret = 1LL * ret * x % mod; return ret;
}

void solve(int n, int m, string a, string b, string c, string d) {
	int cntc, cntd;
	cntc = cntd = 0;
	for (int i = 1; i <= m; ++i) {
		cntc += c[i] == '1', cntd += d[i] == '1';
	}
	f[1] = g[n] = 1;
	int cnta, cntb;
	cnta = cntb = 0;
	for (int i = 1; i < n; ++i) {
		cnta += a[i] == '1', cntb += b[i] == '1';
		f[i + 1] = C(cnta + cntb + cntc - 1, cntc - 1);
	}
	cnta = cntb = 0;
	for (int i = n; i > 1; --i) {
		cnta += a[i] == '1', cntb += b[i] == '1';
		g[i - 1] = C(cnta + cntb + cntd - 1, cntd - 1);
	}
	int sum = 0, cur = 1;
	for (int i = n; i >= 1; --i) {
		int cnt = 0;
		cnt += a[i] == '1', cnt += b[i] == '1';
		if (!cnt) continue;
		cur = cur * cnt % mod;
		sum = (sum + 1LL * cur * f[i]) % mod;
	}
	for (int i = n; i >= 1; --i) {
		int cnt = 0;
		cnt += a[i] == '1', cnt += b[i] == '1';
		if (!cnt) continue;
		res = (res + 1LL * sum * g[i]) % mod;
		sum = (sum - 1LL * cnt * f[i]) % mod;
		if (sum < 0) sum += mod;
		sum = 1LL * sum * pw(cnt, mod - 2) % mod;
	}
}

int main() {
	ios::sync_with_stdio(false);
	prd[0] = inv[0] = 1;
	for (int i = 1; i < 3 * N; ++i) {
		prd[i] = 1LL * i * prd[i - 1] % mod;
		inv[i] = pw(prd[i], mod - 2);
	}
	int n, m;
	string a, b, c, d;
	cin >> n >> m;
	cin >> a >> b >> c >> d;
	bool have = 0;
	a = " " + a, b = " " + b, c = " " + c, d = " " + d; 
	for (int i = 1; i <= n; ++i) {
		have |= a[i] == '1' || b[i] == '1';
	}
	for (int i = 1; i <= m; ++i) {
		have |= c[i] == '1' || d[i] == '1';
	}
	if (!have) {
		cout << 1; return 0;
	}
	solve(n, m, a, b, c, d);
	solve(m, n, c, d, a, b);
	cout << res; 
}