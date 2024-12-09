#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));

    for(int i = 1; i <= k; i++) {
        vector<long long> temp(n + 1, 0);
        long long maxVal = LONG_LONG_MIN;

        for(int j = m * i - 1; j < n; j++) {
            maxVal = max(maxVal, dp[i - 1][j - m + 1]);
            temp[j + 1] = max(temp[j], maxVal + accumulate(p.begin() + j - m + 1, p.begin() + j + 1, 0));
        }

        dp[i] = temp;
    }

    cout << dp[k][n] << endl;

    return 0;
}