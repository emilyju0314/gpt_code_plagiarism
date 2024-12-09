#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int m = ri();
	int l[m], r[m], c[m];
	for (int i = 0; i < m; i++) l[i] = ri() - 1, r[i] = ri() - 1, c[i] = ri();
	std::vector<int> hen[n];
	std::vector<int> finish[n + 1];
	int64_t cost_hen[m];
	for (int i = 0; i < m; i++) hen[l[i]].push_back(i), finish[r[i]].push_back(i);
	int64_t dp[n];
	for (int i = 0; i < m; i++) cost_hen[i] = l[i] ? 1000000000000000000 : c[i];
	for (int i = 0; i < n; i++) dp[i] = 1000000000000000000;
	dp[0] = 0;
	std::multiset<int64_t> costs;
	std::set<int> cur;
	for (int i = 0; i + 1 < n; i++) {
		for (auto j : hen[i]) cur.insert(j), costs.insert(c[j] + dp[i]);
		for (auto j : finish[i]) cur.erase(j), costs.erase(costs.find(c[j] + dp[l[j]]));
		if (costs.size()) dp[i + 1] = *costs.begin();
	}
	std::cout << (dp[n - 1] >= 1000000000000000000 ? -1 : dp[n - 1]) << std::endl;
	return 0;
}
