#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
const ll mod = (1e+9) + 7;

int main() {
	int n, k;
	static ll dp[55][55][2705];
	cin >> n >> k;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int l = 0; l <= k; ++l) {
				dp[i + 1][j][l + 2 * j] = (dp[i + 1][j][l + 2 * j] + dp[i][j][l]) % mod;
				dp[i + 1][j + 1][l + 2 * (j + 1)] = (dp[i + 1][j + 1][l + 2 * (j + 1)] + dp[i][j][l]) % mod;
				dp[i + 1][j][l + 2 * j] = (dp[i + 1][j][l + 2 * j] + dp[i][j][l] * 2 * j) % mod;
				if (j >= 1)
					dp[i + 1][j - 1][l + 2 * (j - 1)] = (dp[i + 1][j - 1][l + 2 * (j - 1)] + dp[i][j][l] * j * j) % mod;
			}
		}
	}
	cout << dp[n][0][k] << endl;
	return 0;
}