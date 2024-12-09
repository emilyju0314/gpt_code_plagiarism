#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int dp[1001][1001];
int v[1001], w[1001];
int main() {
	int W, N;
	int cnt = 1;
	while (scanf("%d", &W), W) {
		scanf("%d", &N);
		rep(i, N)scanf("%d,%d", &v[i], &w[i]);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= W; j++) {
				if (j < w[i]) dp[i + 1][j] = dp[i][j];
				else dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
			}
		}
		int Max = 0, Min = 0;
		for (int i = 0; i <= W; i++) {
			if (Max < dp[N][i]) { Max = dp[N][i]; Min = i; }
		}
		printf("Case %d:\n%d\n%d\n", cnt, Max, Min);
		cnt++;
	}
	return 0;
}