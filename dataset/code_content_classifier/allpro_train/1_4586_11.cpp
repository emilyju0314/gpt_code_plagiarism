#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int pre[110][110];
int dp[110][110][110];
int X[100];
int Y[100];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, P;
	cin >> N >> P;
	for(int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}

	memset(pre, -1, sizeof pre);
	pre[0][0] = max(0, Y[0] - X[0]);
	for(int i = 0; i < N - 1; i++) {
		for(int j = 0; j < N; j++) {
			if(pre[i][j] == -1) continue;
			pre[i + 1][0] = max(0, Y[i + 1] - X[i + 1]);
			int x = max(0, X[i + 1] - pre[i][j]);
			int t = max(0, Y[i + 1] - x);
			pre[i + 1][j + 1] = t;
		}
	}

	const int INF = 1 << 30;
	fill((int*)begin(dp), (int*)end(dp), INF);
	dp[0][0][0] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				if(dp[i][j][k] == INF) continue;
				int sum = dp[i][j][k];
				dp[i + 1][0][k] = min(dp[i + 1][0][k], sum);
				if(sum + pre[i][j] <= P) {
					dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], sum + pre[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for(int j = 0; j <= N; j++) {
		for(int k = 0; k <= N; k++) {
			if(dp[N][j][k] == INF) continue;
			ans = max(ans, k);
		}
	}
	cout << ans << endl;
}