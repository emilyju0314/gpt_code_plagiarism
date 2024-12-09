#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    string t;
    cin >> t;
    int m = t.size();

    vector<long long> dp(k, 0);
    vector<int> lastIdx(26, -1);
    
    for (int i = 0; i < m; i++) {
        int idx = t[i] - 'a';
        dp[idx] = 1;
        for (int j = 0; j < k; j++) {
            if (j != idx) {
                dp[j] += dp[j];
            }
            if (lastIdx[j] != -1) {
                dp[j] %= MOD;
            }
        }
        lastIdx[idx] = i;
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            result += dp[j];
            result %= MOD;
        }
    }

    cout << result << endl;

    return 0;
}