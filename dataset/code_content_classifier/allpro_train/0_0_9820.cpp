#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long m, l, r, k;
    cin >> m >> l >> r >> k;

    vector<long long> fib(3, 1);
    for (int i = 3; i <= r; i++) {
        fib.push_back((fib[i-1] + fib[i-2]) % m);
    }

    long long max_gcd = 0;
    for (int mask = 0; mask < (1 << (r-l+1)); mask++) {
        if (__builtin_popcount(mask) == k) {
            long long curr_gcd = 0;
            for (int i = l; i <= r; i++) {
                if (mask & (1 << (i-l))) {
                    curr_gcd = (curr_gcd == 0) ? fib[i] : gcd(curr_gcd, fib[i]);
                }
            }
            max_gcd = max(max_gcd, curr_gcd);
        }
    }

    cout << max_gcd%m << endl;

    return 0;
}