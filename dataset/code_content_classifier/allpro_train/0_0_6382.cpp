#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> fact(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    auto powmod = [&](long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    };
    
    auto inv = [&](long long x) {
        return powmod(x, MOD - 2);
    };
    
    auto nCr = [&](int n, int r) {
        long long numerator = fact[n];
        long long denominator = (fact[r] * fact[n-r]) % MOD;
        return (numerator * inv(denominator)) % MOD;
    };
    
    long long ans = 1;
    for(int i = 1; i <= min(n-1, k); i++) {
        ans = (ans + (nCr(n, i) * nCr(n-1, i)) % MOD) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}