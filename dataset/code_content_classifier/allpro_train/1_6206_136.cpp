#include <bits/stdc++.h>
using namespace std;
long long S, dp[20001];
int main() {
	cin >> S;
	dp[0]=1;
	for (int i = 1; i <= S; i++) {
		for (int j = i; j >= 3; j--) {
			dp[i] += dp[i - j];
			if (dp[i] > (long long)(1e9+7)) 
				dp[i] -= (long long)(1e9+7);
		}
	}
	cout << dp[S];
}
// 1729