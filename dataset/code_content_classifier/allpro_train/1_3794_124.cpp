#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int mxn = 2006;

int n;
char a[mxn];
char b[mxn];

int mr(int x) { return (x % n + n) % n; }

int M[mxn];

int dl[mxn];
int dr[mxn];

void ini() {
	fill(M, M + n, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			M[i] += a[mr(j + i)] != b[j];
	fill(dl, dl + n, 0);
	fill(dr, dr + n, 0);
	for (int i = 0; i < n * 2; ++i)
		dl[mr(-i)] = b[mr(-i)] == '1' ? 0 : dl[mr(-i + 1)] + 1;
	for (int i = 0; i < n * 2; ++i)
		dr[mr(+i)] = b[mr(+i)] == '1' ? 0 : dr[mr(+i - 1)] + 1;
}

int getm(int r) {
	int re = INT_MAX;
	for (int i = 0; i < n; ++i)
		re = min(re, M[i] + min(mr(i - r), mr(r - i)));
	return re;
}


int getl(int r) {
	int re = 0;
	for (int i = 0; i < n; ++i) if (a[i] == '1')
		if (dr[i] > r)
			re = max(re, dl[i]);
	return re * 2;
}

int solve() {
	ini();
	int re = INT_MAX;
	for (int i = 0; i < n; ++i)
		re = min(re, getl(i) + getm(i) + i);
	return re;
}

int main() {
	scanf("%s%s", a, b);
	n = strlen(a);
	
	if (count(b, b + n, '1') == 0) {
		if (count(a, a + n, '1') == 0)
			puts("0");
		else
			puts("-1");
		return 0;
	}
	
	int ans = solve();
	
	reverse(a, a + n);
	reverse(b, b + n);
	
	ans = min(ans, solve());
	
	cout << ans << endl;
	
	return 0;
}
