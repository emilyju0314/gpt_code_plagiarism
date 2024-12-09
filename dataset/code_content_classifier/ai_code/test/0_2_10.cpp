#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

// Function to calculate power modulo MOD
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        y = y / 2;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    long long n, m, k, r, c, a_x, a_y, b_x, b_y;
    cin >> n >> m >> k >> r >> c >> a_x >> a_y >> b_x >> b_y;

    long long distinct_patterns_a = power(k, r*c);
    long long distinct_patterns_b = power(k, r*c);

    long long result = (distinct_patterns_a * distinct_patterns_b) % MOD;
    cout << result << endl;

    return 0;
}