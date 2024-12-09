#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    while(n > 0) {
        if(n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, a, b;
    long long k;
    cin >> n >> a >> b >> k;

    long long ans = 0;
    for(int i = 0; i <= n; i++) {
        long long sum = i * a;
        if(sum > k) break;
        long long rest = k - sum;
        if(rest % b == 0 && rest / b <= n) {
            long long comb1 = 1;
            long long comb2 = 1;
            for(int j = 0; j < n; j++) {
                comb1 = comb1 * (rest - j + MOD) % MOD;
                comb2 = comb2 * (j + 1) % MOD;
            }
            long long ways = comb1 * mod_pow(comb2, MOD - 2) % MOD;
            long long ways2 = mod_pow(2, n) - ways;
            ans = (ans + ways * ways2) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}