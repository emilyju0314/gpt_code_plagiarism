#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long fastExp(long long base, long long exp, int mod) {
    long long ans = 1;
    while (exp > 0) {
        if(exp % 2 == 1) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        long long ans = 0;
        for (int i = 0; i <= 31; i++) {
            if ((k & (1 << i)) != 0) {
                ans += fastExp(n, i, MOD);
                ans = ans % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}