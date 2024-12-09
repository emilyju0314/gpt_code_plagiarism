#include <iostream>
using namespace std;

const int MOD = 1000003;

long long power(long long x, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (x * power(x, n-1)) % MOD;
    long long half = power(x, n/2);
    return (half * half) % MOD;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        long long x, d, n;
        cin >> x >> d >> n;

        long long first = x % MOD;
        long long ratio = d % MOD;

        long long product = (first * power(ratio, n)) % MOD;

        cout << product << endl;
    }

    return 0;
}