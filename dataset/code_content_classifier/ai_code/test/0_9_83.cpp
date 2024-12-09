#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    long long mult = 1;
    while (mult <= n) {
        long long next = (n / (mult * 10)) * mult + min(mult, max(n % (mult * 10) - mult + 1, 0LL));
        ans = (ans + (next - mult + 1) % MOD * ((n / mult) % MOD) % MOD) % MOD;
        mult *= 10;
    }

    cout << (ans % MOD + MOD) % MOD << endl;

    return 0;
}