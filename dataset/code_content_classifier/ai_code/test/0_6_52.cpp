#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        long long ans = 0;
        long long cur_power = 1;

        while (k > 0) {
            long long max_power = 0;
            while (power(n, max_power + 1) <= k) {
                max_power++;
            }
            ans += cur_power * power(n, max_power);
            ans %= MOD;
            cur_power++;
            k -= power(n, max_power);
        }

        cout << ans << endl;
    }

    return 0;
}