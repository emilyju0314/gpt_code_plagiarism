#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int n;
vector<int> b;
vector<vector<long long>> dp;

long long countTrees(int v, int prev) {
    if (v >= n) return 1;

    if (dp[v][prev] != -1) return dp[v][prev];

    long long ans = 0;
    for (int i = v + 1; i < n; i++) {
        if (b[i] > b[prev]) {
            ans = (ans + countTrees(i, v)) % MOD;
        }
    }

    return dp[v][prev] = ans;
}

int main() {
    cin >> n;
    b.resize(n);
    dp.assign(n, vector<long long>(n, -1));

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long result = countTrees(1, 0);
    cout << result << endl;

    return 0;
}