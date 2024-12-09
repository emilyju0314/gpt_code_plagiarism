#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    
    return res;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        vector<long long> specialNumbers;
        
        for (int i = 0; i < 32; i++) {
            if ((k >> i) & 1) {
                specialNumbers.push_back(power(n, i));
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < specialNumbers.size(); i++) {
            ans = (ans + specialNumbers[i]) % MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}