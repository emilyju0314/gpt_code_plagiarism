#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % MOD;
}

int subtract(int a, int b) {
    return (a - b + MOD) % MOD;
}

int multiply(int a, int b) {
    return ((long long)a * b) % MOD;
}

int n, m, a, b;
vector<vector<int>> dp; // dp[i][j] represents the number of ways to reach node i with sum of weights j

void calculate_dp() {
    dp.resize(n + 1, vector<int>(m + 1, 0));
    dp[1][0] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = add(dp[i][j], dp[k][j - 1]);
            }
        }
    }
}

int count_beautiful_trees() {
    calculate_dp();

    int result = 0;
    for (int i = 1; i <= m; i++) {
        int left = dp[a][i - 1];
        int right = dp[b][m - i];
        result = add(result, multiply(left, right));
    }
    return result;
}

int main() {
    cin >> n >> m >> a >> b;

    int answer = count_beautiful_trees();
    cout << answer << endl;

    return 0;
}