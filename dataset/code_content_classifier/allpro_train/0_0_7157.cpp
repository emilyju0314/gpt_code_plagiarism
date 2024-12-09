#include <iostream>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    long long k, p;
    cin >> k >> p;
    
    long long ans = 0;
    long long mul = 10;
    long long mod = power(10, k, p);
    
    for (long long d = 1; d <= k; ++d) {
        long long rev_d = 0, cur_pow = 1;
        for (long long i = 1; i <= d; ++i) {
            rev_d += (cur_pow * (d % 10)) % p;
            rev_d %= p;
            cur_pow = (cur_pow * mul) % p;
            d /= 10;
        }
        
        int num = (d * mul) % p;

        ans += (num + rev_d) % p;
        ans %= p;
    }

    cout << ans << endl;
    
    return 0;
}