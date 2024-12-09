#include <iostream>
#include <cmath>

using namespace std;

const long long MOD = 998244353;
const long long MOD_OUT = 1000000007;

long long calculate_sum(long long n) {
    long long sum = 0;
    long long p10 = 10;
    for(long long d = 1; d <= n; d *= 10, p10 *= 10) {
        long long right = min(p10 - 1, n);
        long long k = (right - d + 1) % MOD;
        long long diff = right / d - (d / 10 - 1);
        long long x = (k*diff) % MOD;
        sum = (sum + x) % MOD;
    }
    return sum;
}

int main() {
    long long n;
    cin >> n;

    long long sum = calculate_sum(n);
    cout << (sum * 10) % MOD_OUT << endl;

    return 0;
}