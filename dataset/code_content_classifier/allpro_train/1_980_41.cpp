#include <bits/stdc++.h>
#define maxn 150010
using namespace std;
int n, mod, w[2][2 * maxn + 5], s[2][2 * maxn + 5], ans[505];
int main()
{
	cin >> n >> mod;
	w[0][maxn] = s[0][maxn] = 1;
	for (int i = maxn; i <= 2 * maxn; i ++ ) s[0][i] = 1;
	for (int i = 1; i <= n; i ++ )
	{
		int curs = 1, I = i & 1, J = I ^ 1;
		memset(w[I], 0, sizeof(w[I])), memset(s[I], 0, sizeof(s[I]));
		for (int u = i * (i - 1) / 2, j = -u + maxn; j <= u + maxn; j ++ ) w[I][j] = curs, curs = (0ll + curs - s[J][j] + s[J][j - i] + s[J][j + i] - s[J][j] + 2ll * mod) % mod;
		for (int j = maxn - i * (i - 1) / 2, v = (i + 2) * (i + 1) / 2 + maxn; j <= v; j ++ ) s[I][j] = (s[I][j - 1] + w[I][j]) % mod;
		for (int j = 1; j < i; j ++ ) ans[i] = (ans[i] + 1ll * (s[J][(i + 1) * i / 2 + maxn] - s[J][j + maxn] + mod) % mod * (i - j)) % mod;
	}
	for (int i = 2; i <= n; i ++ ) ans[i] = (ans[i] + 1ll * i * ans[i - 1]) % mod;
	cout << ans[n] << endl;
}