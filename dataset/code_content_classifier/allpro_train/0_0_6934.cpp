#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long fast_pow(long long base, long long exp) {
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
    long long n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    long long fn = 0;
    long long a = f1 % MOD;
    long long b = f2 % MOD;
    long long cc = fast_pow(c % MOD, 2);

    for (int x = 4; x <= n; x++) {
        fn = (cc * a % MOD * b % MOD * fn % MOD) % MOD;
        a = b;
        b = fn;
    }

    cout << fn << endl;

    return 0;
}