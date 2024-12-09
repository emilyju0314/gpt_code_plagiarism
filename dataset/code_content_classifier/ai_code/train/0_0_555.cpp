#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    long long result = 0;
    long long base = 10;
    long long fact_n = 1;
    long long fact_k = 1;
    long long fact_nk = 1;
    for (int i = 1; i <= n; i++) {
        fact_n = (fact_n * i) % MOD;
        if (i == k) fact_k = fact_n;
        if (i == n - k) fact_nk = fact_n;
    }

    for (int i = 0; i < n; i++) {
        long long mul = (s[i] - '0') % MOD;
        result = (result + (mul * fact_n) % MOD) % MOD;
        fact_n = (fact_n * power(base, MOD - 2)) % MOD;
    }

    result = (result * power((fact_k * fact_nk) % MOD, MOD - 2)) % MOD;
    cout << result << endl;

    return 0;
}