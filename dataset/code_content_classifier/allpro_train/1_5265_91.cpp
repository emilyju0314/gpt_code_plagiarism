#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

ll dp[N][N];
ll fact[N], inv[N];


ll bpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	fact[0] = inv[0] = 1;
	for (int i=1; i<N; i++)
		fact[i] = fact[i-1] * i % MOD, inv[i] = bpow(fact[i], MOD - 2);

	for (int i=0; i<N; i++)
		dp[i][0] = 1;
	for (int i=a; i<=b; i++)
		for (int j=1; j<=n; j++)
		{
			dp[i][j] = dp[i-1][j];
			for (int k=c; k<=d && j >= k * i; k++)
				dp[i][j] = (dp[i][j] + dp[i-1][j-k*i] * bpow(inv[i], k) % MOD * inv[k] % MOD) % MOD;
		}
	cout << dp[b][n] * fact[n] % MOD << "\n";

	return 0;
}