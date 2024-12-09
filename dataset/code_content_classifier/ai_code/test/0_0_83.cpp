#include <iostream>

using namespace std;

const long long mod = 998244353;
const long long base = 1e9 + 7;

long long add(long long a, long long b) {
    return (a + b) % base;
}

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    long long mul = 1;

    while (mul * 10 <= n) {
        ans = add(ans, ((n / (mul * 10) * mul) % mod) * 45 % mod);
        mul *= 10;
    }

    ans = add(ans, ((mul + (n - mul + 1)) * (n - mul + 1) / 2) % mod);

    cout << ans << endl;

    return 0;
}