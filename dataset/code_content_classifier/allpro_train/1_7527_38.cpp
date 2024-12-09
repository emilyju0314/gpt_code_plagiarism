#include <iostream>
#include <string>
using namespace std;

long long n, res[22][55][55], power26[27], mod = 1000000007; string S[55];

long long solve(int pos, int l, int r) {
	if (l > r) return 1;
	if (res[pos][l][r] >= 1) return res[pos][l][r] - 1;
	if (pos == 20) return 1;
	long long dp[28][55];
	for (int i = l - 1; i <= r; i++) {
		for (int j = 0; j < 28; j++) dp[j][i] = 0;
	}
	dp[0][l - 1] = 1;
	for (int i = 0; i < 27; i++) {
		for (int j = l - 1; j <= r; j++) {
			long long P = 1;
			for (int k = j; k <= r; k++) {
				if (pos == 19 && k - j >= 2) continue;

				if (k != j && S[k][pos] != (char)(95 + i + 1) && (i == 0 || S[k][pos] != '?')) P = 0;
				long long Q = dp[i][j] * P*solve(pos + 1, j + 1, k);
				dp[i + 1][k] += Q; dp[i + 1][k] %= mod;
			}
		}
	}
	res[pos][l][r] = dp[27][r] + 1;
	return res[pos][l][r] - 1;
}

int main() {
	cin >> n;
	power26[0] = 1; for (int i = 1; i < 21; i++) { power26[i] = (power26[i - 1] * 26LL) % mod; }
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
		while (S[i].size() <= 20) S[i] += (char)(96);
	}
	cout << solve(0, 1, n) << endl;
	return 0;
}
