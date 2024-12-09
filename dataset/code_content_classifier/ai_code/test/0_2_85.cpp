#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;

    while(y > 0) {
        if(y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> fact(n + 1);
    vector<long long> inv(n + 1);

    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % m;
        inv[i] = power(fact[i], m - 2, m);
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        long long coeff = (fact[n] * inv[i]) % m;
        coeff = (coeff * inv[n - i + 1]) % m;
        ans = (ans + coeff) % m;
    }

    ans = (ans * power(n + 1, n - 1, m)) % m;
    cout << ans << endl;

    return 0;
}