#include <iostream>

using namespace std;

long long power(long long x, long long n, long long mod) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return result;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long k, l, r, p;
        cin >> k >> l >> r >> p;
        
        long long ans = 0;
        for (long long i = l; i <= r; i++) {
            if (lcm(k, i) % p == 0) {
                ans++;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}