#include <iostream>
#include <cmath>

using namespace std;

const long long M = 998244353, MOD = 1e9 + 7;

long long mod(long long x) {
    return (x % MOD + MOD) % MOD;
}

long long solve(long long n) {
    long long ans = 0, base = 1;

    while (base * 10 <= n) {
        long long next = base * 10;
        ans = mod(ans + 9 * base * (next - 1 - base + 1) / 2);
        base = next;
    }

    ans = mod(ans + (n - base + 1) * (base - 1));

    return ans;
}

int main() {
    long long n;
    cin >> n;

    long long result = solve(n);

    cout << result << endl;

    return 0;
}