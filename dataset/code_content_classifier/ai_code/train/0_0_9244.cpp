#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long L, R;
    cin >> L >> R;

    long long ans = 0;
    for (int i = 0; i < 60; i++) {
        long long base = 1LL << i;
        long long L2 = max(L, base);
        long long R2 = min(R, base * 2 - 1);
        if (L2 <= R2) {
            long long cnt = (R2 - L2 + 1) * (R2 - L2 + 2) / 2 % MOD;
            ans = (ans + ((cnt % MOD) << i) % MOD) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}