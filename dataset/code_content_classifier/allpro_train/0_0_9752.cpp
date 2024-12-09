#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int k;
    cin >> k;
    
    vector<long long> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    
    long long q = 1;
    for (int i = 0; i < k; i++) {
        q = (q * arr[i]) % (MOD - 1);
    }
    
    long long p = (q / 2) % MOD;
    if (q % 2 != 0) {
        if (p % 2 == 0) {
            p = (p + MOD) / 2;
        } else {
            p = (p + MOD) / 2;
            p = (p + MOD) % MOD;
        }
    }
    
    long long g = gcd(p, q);
    p = (p / g) % MOD;
    q = (q / g) % MOD;
    
    cout << p << "/" << q << endl;
    
    return 0;
}