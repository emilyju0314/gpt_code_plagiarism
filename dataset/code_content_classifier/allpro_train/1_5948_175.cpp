#include <bits/stdc++.h>

using namespace std;

int dp[6005];
pair <int, int> a[3005];

int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
	
	sort(a, a + n);
	
	int maxTime = t + a[n - 1].first - 1;
	
	for (int i = 0; i <= maxTime; i++) dp[i] = -1;
	dp[0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = maxTime; j >= a[i].first; j--) {
			if (j - a[i].first >= t) continue;
			if (dp[j - a[i].first] != -1) dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
		}
	}
	
	int res = *max_element(dp, dp + maxTime + 1);
	
	printf("%d\n", res);
}
