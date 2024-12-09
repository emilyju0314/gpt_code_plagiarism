#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int ans = 0;
        for (int i = 0; i <= 31; i++) {
            if (k & (1 << i)) {
                ans = (ans + power(n, i)) % MOD;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}