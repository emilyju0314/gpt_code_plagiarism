#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long n, k, M, D;
    cin >> n >> k >> M >> D;

    long long ans = 0;
    for (long long x = 1; x <= M; x++) {
        if (n % x == 0) {
            long long cycles = n / x;
            if (cycles <= k) {
                ans = max(ans, min(cycles, D) * x);
            } else {
                long long max_cycles = k * (n / gcd(n, k));
                if (max_cycles >= cycles) {
                    ans = max(ans, min(D, cycles/k) * x);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}