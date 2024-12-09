#include <iostream>
#include <vector>

using namespace std;

long long maxScore(vector<int>& a) {
    int n = a.size();
    vector<long long> dp(n);
    long long res = 0;

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = a[i];
        if (i + a[i] < n) {
            dp[i] += dp[i + a[i]];
        }
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << maxScore(a) << endl;
    }

    return 0;
}