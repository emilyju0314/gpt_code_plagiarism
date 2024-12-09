#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> cnt(100005, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    vector<long long> dp(100005, 0);
    dp[0] = 0;
    dp[1] = cnt[1];

    for (int i = 2; i < 100005; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + i * cnt[i]);
    }

    cout << dp[100004] << endl;

    return 0;
}