#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int dp[N][3];

int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		dp[i][0] = a+max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b+max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c+max(dp[i-1][0], dp[i-1][1]);
	}

	cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}