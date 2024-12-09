#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n, f;
        cin >> n >> f;
        
        long long ans = 1;
        for (int i = 1; i < f; ++i) {
            ans = (ans * power(n - i, f, MOD)) % MOD;
        }
        ans = (ans * power(f, MOD - 2, MOD)) % MOD;
        
        cout << ans << endl;
    }
    
    return 0;
}