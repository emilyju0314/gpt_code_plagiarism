#include <iostream>
using namespace std;

const int MOD = 1000000007;

int power(int x, int y, int p) {
    int res = 1;
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
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            if ((k >> i) & 1) {
                ans = (ans + power(n, i, MOD)) % MOD;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}