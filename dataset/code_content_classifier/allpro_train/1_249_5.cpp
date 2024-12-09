#include <bits/stdc++.h>
#define int long long
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? 1e18 : 1e9;
const int MOD = 1000000007;
const long double EPS = 1e-8;

int n;
int q[100010];
int dp[100010][2];
bool b[100010];

signed main() {
	cin >> n;
	rep (i, n) {
		cin >> q[i];
		b[i] = true;
		for (int j = 2; j * j <= q[i]; j++) b[i] = b[i] && (q[i] % j != 0 || q[i] == j);
	}
	rep (i, n) {
		// i 番目を q とする
		if (i == 0) {
			dp[i][0] = b[i];
			continue;
		}
		if (b[i]) {
			if (q[i - 1] < q[i]) dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
			if (i > 1 && q[i - 2] < q[i]) dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
		}
		// i 番目を e とする
		dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
	}
	cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
	//rep (i, n + 1) cout << dp[i][0] << " " << dp[i][1] << endl;
	return 0;
}
