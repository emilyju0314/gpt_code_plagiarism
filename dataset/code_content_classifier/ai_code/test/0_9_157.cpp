#include <iostream>
#include <vector>
#include <cstring>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<long long> cnt(n + 1, 0);
    cnt[0] = 1;

    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] * i % MOD;
    }

    long long ans = 0;

    for (int i = 0; i <= k; i++) {
        long long choose_k = cnt[k] * cnt[n - k] % MOD;
        long long combinations = cnt[n] * choose_k % MOD;
        ans = (ans + combinations) % MOD;
    }

    cout << ans << endl;

    return 0;
}