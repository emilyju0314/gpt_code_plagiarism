#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = (result * k) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}