#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return (a * power(a, b-1)) % MOD;
    long long half = power(a, b/2);
    return (half * half) % MOD;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<pair<int, string>> colored_nodes(n);
    map<int, string> colors;
    for (int i = 0; i < n; i++) {
        int v;
        string s;
        cin >> v >> s;
        colored_nodes[i] = {v, s};
        colors[v] = s;
    }

    vector<int> dp(2001, 0);
    dp[0] = 1;

    for (int i = 1; i <= k; i++) {
        vector<int> next_dp(2001, 0);
        for (int j = 0; j <= 2000; j++) {
            if (dp[j] == 0) continue;
            next_dp[j] = (next_dp[j] + dp[j]) % MOD;
            next_dp[j+1] = (next_dp[j+1] + dp[j]) % MOD;
        }
        dp = next_dp;
    }

    vector<int> valid(2001, 1);
    for (auto node : colored_nodes) {
        int v = node.first;
        string color = node.second;

        for (int i = 0; i <= 2000; i++) {
            if (i == v) continue;
            if (abs(v - i) == 1 || (v % 2 == 0 && i == v + 1) || (v % 2 == 1 && i == v - 1)) {
                if ((color == "white" || color == "yellow") && (colors[i] == "white" || colors[i] == "yellow")) {
                    valid[i] = 0;
                }
                if ((color == "green" || color == "blue") && (colors[i] == "green" || colors[i] == "blue")) {
                    valid[i] = 0;
                }
                if ((color == "red" || color == "orange") && (colors[i] == "red" || colors[i] == "orange")) {
                    valid[i] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 2000; i++) {
        if (valid[i]) ans = (ans + dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}