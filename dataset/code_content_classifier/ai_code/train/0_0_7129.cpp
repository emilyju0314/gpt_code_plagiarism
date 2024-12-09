#include <iostream>
using namespace std;

const int MOD = 1000000009;

int powMod(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int ans = powMod(2, m) - 1;
    ans = powMod(ans, n);
    
    cout << ans << endl;
    
    return 0;
}