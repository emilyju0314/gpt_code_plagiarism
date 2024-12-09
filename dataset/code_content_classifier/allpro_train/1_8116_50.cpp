#include <bits/stdc++.h>
using namespace std;

const int maxn = 500, mod = 1e9 + 7;
int n, X, fact[maxn + 3], finv[maxn + 3], c[maxn + 3], f[maxn + 3][maxn + 3][maxn + 3], p[maxn + 3][maxn + 3];

int qpow(int a, int b) {
	if (a <= maxn && b <= maxn && p[a][b]) return p[a][b];
	int c = 1, d = a, e = b;
	for (; b; b >>= 1, a = 1ll * a * a % mod) if (b & 1) c = 1ll * a * c % mod;
	if (d <= maxn && e <= maxn) p[d][e] = c;
	return c;
}

void prework(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
	finv[n] = qpow(fact[n], mod - 2);
	for (int i = n; i; i--) finv[i - 1] = 1ll * finv[i] * i % mod;
}

int C(int n, int m) {
	if (n < 0 || m < 0 || m > n) return 0;
	return 1ll * fact[n] * finv[m] % mod * finv[n - m] % mod;
}

int main() {
	scanf("%d %d", &n, &X);
	prework(X);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x), c[x]++;
	}
	f[X + 1][0][0] = 1;
	for (int i = X; i; i--) {
		for (int j = 0; j <= X; j++) {
			for (int k = i * j; k <= X; k++) {
				for (int l = 0; l <= j && l * i <= k; l++) {
					f[i][j][k] = (f[i][j][k] + 1ll * f[i + 1][j - l][k - l * i] * finv[l]) % mod;
				}
				f[i][j][k] = 1ll * f[i][j][k] * qpow(k - (i - 1) * j, c[i]) % mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= X; i++) {
		for (int j = 0; j <= X; j++) {
			ans = (ans + 1ll * f[1][i][j] * fact[i] % mod * ((X - j) & 1 ? mod - 1 : 1) % mod * C(X - j + 1, i)) % mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}