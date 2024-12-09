#include <iostream>

#define MOD 1000000007

using namespace std;

// Function to calculate power with modulo
long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Calculate number of dots
        long long ans = (power(2, n + m, MOD) - 1 + MOD) % MOD;
        cout << ans << endl;
    }

    return 0;
}