#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
typedef long long ll;

int n, m;
int a[N], v[N], f[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int lim = 0;
		scanf("%d%d", &a[i], &lim);
		for(int x, j = 1; j <= lim; ++j) {
			scanf("%d", &x);
			--x; v[i] |= 1 << x;
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < (1 << n); ++j) {
			f[i][j] = min(f[i][j], f[i - 1][j]);
			f[i][j | v[i]] = min(f[i][j | v[i]], f[i][j] + a[i]);
		}
	}
	if(f[m][(1 << n) - 1] == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", f[m][(1 << n) - 1]);
}