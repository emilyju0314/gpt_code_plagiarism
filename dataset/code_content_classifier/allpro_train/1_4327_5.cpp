#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000007;

int F[1001], C[1001][1001], D[1001][1001];

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

vector<vector<int> > f(int N, ll t) {
	vector<vector<int> > a(N + 1);
	for (int n = 1; n <= N; n++) {
		vector<int> dp(N / n + 1);
		dp[0] = 1;
		for (int i = 0; i <= N / n; i++)
			for (int j = 1; i + j <= N / n; j++) {
				if (gcd(t, j * n) != j) continue;
				ll x = dp[i];
				x = x * C[i + j - 1][j - 1] % MOD;
				x = x * F[j - 1] % MOD;
				x = x * D[n][j - 1] % MOD;
				dp[i + j] = (dp[i + j] + x) % MOD;
			}
		a[n] = dp;
	}
	return a;
}

int main() {
	F[0] = 1;
	for (int i = 1; i <= 1000; i++)
		F[i] = (ll)F[i - 1] * i % MOD;
	for (int i = 0; i <= 1000; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	for (int i = 1; i <= 1000; i++) {
		D[i][0] = 1;
		for (int j = 1; j <= 1000; j++)
			D[i][j] = (ll)D[i][j - 1] * i % MOD;
	}
	int N; ll X, Y, Z;
	cin >> N >> X >> Y >> Z;
	vector<vector<int> > a = f(N, 2), b = f(N, abs(X - Y + Z));
	if (!X && !Y && !Z) {
		cout << (ll)a[1][N] * D[N][N] % MOD << endl;
		return 0;
	}
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int n = 1; n <= N; n++)
		for (int k = N; k >= 0; k--) {
			ll z = 1;
			for (int i = 1; k + i * n <= N; i++) {
				z = z * C[i * n - 1][n - 1] % MOD * F[n - 1] % MOD;
				ll x = dp[k];
				x = x * C[k + i * n][i * n] % MOD;
				x = x * z % MOD;
				x = x * a[n][i] % MOD;
				x = x * b[n][i] % MOD;
				dp[k + i * n] = (dp[k + i * n] + x) % MOD;
			}
		}
	cout << dp[N] << endl;
}