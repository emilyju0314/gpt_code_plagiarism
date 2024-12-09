#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> fact(n+3, 1);
    for (int i = 1; i <= n+2; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    long long ans = (2 * (fact[n+2] - power(2, n+1) + MOD) % MOD) * power(fact[n+1], MOD-2) % MOD;
    cout << ans << endl;
    return 0;
}