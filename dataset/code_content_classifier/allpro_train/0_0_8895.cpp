#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<int, int> cnt;
    vector<int> dp(N+1);
    dp[N] = 1;
    int ans = 0, cur = 0;

    for (int i = N-1; i >= 0; i--) {
        cur ^= A[i];
        if (cnt.find(cur) != cnt.end()) {
            dp[i] = dp[i+1] + cnt[cur];
        } else {
            dp[i] = dp[i+1];
        }
        cnt[cur] += dp[i+1];
        cnt[cur] %= MOD;
        if (cur == 0) {
            ans += dp[i];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}