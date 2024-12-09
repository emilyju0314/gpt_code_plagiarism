#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int mod = 1051131;

vector<int> a;

int main() {
    int m, s;
    long long t;
    cin >> m >> t >> s;

    for(int i = 0; i < s; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    vector<vector<int>> dp(1 << m, vector<int>(t + 1, 0));
    for(int i = 0; i < s; i++) {
        dp[i][0] = 1;
    }

    for(int j = 1; j <= t; j++) {
        for(int i = 0; i < (1 << m); i++) {
            for(int k = 0; k < m; k++) {
                int next = i ^ (1 << k);
                dp[next][j] = (dp[next][j] + dp[i][j-1]) % mod;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < (1 << m); i++) {
        ans = (ans + dp[i][t]) % mod;
    }

    // Calculate xor-sum of ans
    int result = 0;
    for(int i = 0; i < m; i++) {
        result = (result ^ ans);
    }

    cout << result << endl;

    return 0;
}