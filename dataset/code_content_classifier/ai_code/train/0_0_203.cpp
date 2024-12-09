#include <iostream>
#include <vector>
#include <cmath>

#define mod 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> powers(25);
    powers[0] = 1;
    for (int i = 1; i < 25; i++) {
        powers[i] = (powers[i - 1] * 2) % mod;
    }

    vector<long long> cnt(1 << 20, 0);
    for (int i = 1; i <= n; i++) {
        cnt[a[i - 1]]++;
    }

    for (int i = 0; i < 20; i++) {
        for (int mask = 0; mask < (1 << 20); mask++) {
            if (mask & (1 << i)) {
                cnt[mask] += cnt[mask ^ (1 << i)];
            }
        }
    }

    long long ans = 0;
    for (int mask = 0; mask < (1 << 20); mask++) {
        int k = __builtin_popcount(mask);
        if (k % 2 == 0) {
            ans = (ans + powers[cnt[mask]] - 1 + mod) % mod;
        } else {
            ans = (ans - powers[cnt[mask]] + 1 + mod) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}