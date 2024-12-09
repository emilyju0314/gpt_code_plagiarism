#include <iostream>
#define MOD 998244353
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    long long ans = binpow(m, n-2); // Choose the fixed pair of equal elements
    ans = (ans * (n-2)) % MOD; // Choose the position of the fixed pair
    ans = (ans * (n-1)) % MOD; // Choose the value of the remaining elements

    cout << ans << endl;

    return 0;
}