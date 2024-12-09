#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
inline int read()
{
	int f = 1, x = 0;
	char ch;

	do{
		ch = getchar();
		if (ch == '-')
			f = -1;
	}while(ch < '0' || ch > '9');
	do{
		x = x * 10 + ch - '0';
		ch = getchar();
	}while(ch >= '0' && ch <= '9');
	return f * x;
}
const int N = 100;
const int M = 2e5;
const int mod = 1e9 + 7;

int n, q;
int b[N + 1], c[N + 1], sumc[N + 1];
int f[N + 1][N * N + 1], g[N * N + 1], ans[M + 1];
int sum = 1, l = M / 2, r = M / 2;

inline int dp(int x)
{
	memset(f, 0, sizeof(int) * (N + 1));
	f[0][0] = 1;
	for (int i = 0; i <= N * N; i++)
		g[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = sumc[i]; j >= 0; j--)
			f[i][j] = (g[j] - ((j - c[i] > 0)?g[j - c[i] - 1]:0) + mod) % mod;
		for (int j = 0; j < x * i + b[i - 1]; j++)
			f[i][j] = 0;
		g[0] = f[i][0];
		for (int j = 1; j <= N * N; j++)
			g[j] = (g[j - 1] + f[i][j]) % mod;
	}
	return g[sumc[n]];
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		c[i] = read();
		sumc[i] = sumc[i - 1] + c[i];
		sum = 1ll * sum * (c[i] + 1) % mod;
	}
	for (int i = 1; i < n; i++)
		b[i] = b[i - 1] + read();
	for (int i = 1; i < n; i++)
		b[i] += b[i - 1];
	q = read();
	for (int i = 1; i <= n; i++) {
		l = min(l, (int)ceil(-b[i - 1] / i));
		r = min(r, (int)floor((sumc[i] - b[i - 1]) / i));
	}
	l = max(l, -M / 2);

	for (int i = l; i <= r; i++)
		ans[i + M / 2] = dp(i);

	for (int i = 1; i <= q; i++) {
		int x = read();
		printf("%d\n", x < l?sum:(x > r?0:ans[x + M / 2]));
	}
	return 0;
}
