#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int m;
    cin >> m;

    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        unordered_map<int, int> new_dp;
        for (auto& item : dp) {
            int prev_sum = item.first;

            new_dp[prev_sum + a[i]] = (new_dp[prev_sum + a[i]] + item.second) % m;
            new_dp[prev_sum + b[i]] = (new_dp[prev_sum + b[i]] + item.second) % m;
        }

        dp = new_dp;
    }

    int ans = 0;
    for (auto& item : dp) {
        if (item.first == n) {
            ans = (ans + item.second) % m;
        }
    }

    cout << ans << endl;

    return 0;
}