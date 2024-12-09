#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    
    long long res = power(x, y / 2);
    res = (res * res) % MOD;
    
    if (y % 2 == 1) {
        res = (res * x) % MOD;
    }
    
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (m < n) {
        cout << 0 << endl;
    } else {
        long long ans = power(2, m) - 1;
        ans = power(ans, n);
        cout << ans << endl;
    }

    return 0;
}