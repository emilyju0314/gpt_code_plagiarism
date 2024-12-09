#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 9;

int power(int base, int exp) {
    int result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * 1LL * base) % MOD;
        }
        base = (base * 1LL * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        s[i] = (c == '+') ? 1 : -1;
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum = (sum + s[i] * 1LL * power(a, n - i) * 1LL * power(b, i)) % MOD;
    }

    int v = (power(a, k) - 1 + MOD) % MOD * power(a - 1, MOD - 2) % MOD;
    int x = power(b, k);
    int q = power(a, n - k) * 1LL * s[0] % MOD * v % MOD;
    int y = (power(q, (n + 1) / k) - 1 + MOD) % MOD * power(q - 1, MOD - 2) % MOD;

    x = x * 1LL * y % MOD;

    sum = sum * 1LL * x % MOD;

    if (sum < 0) {
        sum += MOD;
    }

    cout << sum << endl;

    return 0;
}