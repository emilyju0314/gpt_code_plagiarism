#include "iostream"
#include "algorithm"
#include "string"
#include "set"
#include "vector"
#include "queue"
#include "iomanip"
using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	vector<long long int>v(N+1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<vector<long long int>>dp(M + 1, vector<long long int>(N + 2));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		vector<vector<long long int>>ddp(M + 1, vector<long long int>(N + 2));
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= N + 1; k++) {
				if (k) {
					if (j + v[i] <= M) {
						ddp[j + v[i]][k] += dp[j][k];
					}
					ddp[j][k] += dp[j][k];
				}
				else {
					if (j + v[i] <= M) {
						ddp[j + v[i]][k] += dp[j][k];
					}
					ddp[j][i] += dp[j][k];
				}
			}
		}
		dp = ddp;
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= N + 1; k++) {
				dp[j][k] %= MOD;
			}
		}
	}
	long long int ans = 0;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (i + v[j] > M||!j) {
				ans += dp[i][j];
				ans %= MOD;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
