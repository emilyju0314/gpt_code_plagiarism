#include <iostream>
#include <vector>
#include <map>

const int MOD = 1e9 + 7;

int n, m;
int dp[55][55][55][55];
std::vector<std::pair<int, int>> changes;

int dfs(int s1, int t1, int s2, int t2) {
    if (dp[s1][t1][s2][t2] != -1) {
        return dp[s1][t1][s2][t2];
    }

    if (s1 + t1 > m || s2 + t2 > m) {
        dp[s1][t1][s2][t2] = 0;
        return 0;
    }

    int res = 1;
    for (std::pair<int, int> change : changes) {
        res = (res + dfs(s1 + change.first, t1 + change.second, s2, t2)) % MOD;
        res = (res + dfs(s1, t1, s2 + change.first, t2 + change.second)) % MOD;
    }

    dp[s1][t1][s2][t2] = res;
    return res;
}

int main() {
    std::cin >> n >> m;

    changes.push_back({1, 1});
    changes.push_back({1, 0});
    changes.push_back({0, 1});

    memset(dp, -1, sizeof(dp));

    int result = dfs(1, 0, 0, 1);

    std::cout << result << std::endl;

    return 0;
}