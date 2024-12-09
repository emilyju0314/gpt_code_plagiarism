#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int n, m, p, cur_p, odd_pos;
vector<int> g[605], revg[605];
bool mark[605];
int dp[605][605];

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2) res = 1LL * res * a % p;
        a = 1LL * a * a % p;
        b /= 2;
    }
    return res;
}

int dfs(int u) {
    if (mark[u]) return 0;
    mark[u] = true;
    for (auto v : g[u]) {
        dp[odd_pos][u] += dfs(v);
        dp[odd_pos][u] %= p;
    }
    return dp[odd_pos][u];
}

int getInv() {
    int res = 0;
    for (int i = 1, j; i <= n; i++) {
        for (j = i+1; j <= n; j++) {
            if (cur_p == 1) {
                res += dp[i][n] < dp[j][n];
            } else {
                res += dp[i][n] > dp[j][n];
            }
        }
    }
    return (res % 2) ? -1 : 1;
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        revg[v].push_back(u);
    }

    long long answer = 0;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[j][n] = 0;
        dp[i][n] = 1;
        odd_pos = i;
        fill(mark+1, mark+n+1, false);
        for (int j = 1; j <= n; j++) if (!mark[j]) dfs(j);
        for (auto node : revg[i]) {
            for (int j = 1; j <= n; j++) dp[j][n] = 0;
            int old_dp = dp[node][n];
            dp[node][n] = 1;
            odd_pos = node;
            fill(mark+1, mark+n+1, false);
            for (int j = 1; j <= n; j++) if (!mark[j]) dfs(j);
            if ((dp[i][n] < dp[node][n]) != (old_dp < dp[node][n])) {
                answer += power(p-2, n-1);
                answer %= p;
                st.insert(i);
                break;
            }
            dp[node][n] = old_dp;
        }
    }
    for (int i = 1; i <= n; i++) {
        answer *= i;
        answer %= p;
    }
    answer *= getInv() + p;
    answer %= p;

    cout << answer << endl;
    
    return 0;
}