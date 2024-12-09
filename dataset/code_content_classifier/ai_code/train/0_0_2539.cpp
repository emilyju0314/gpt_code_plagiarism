#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

long long binpow(long long base, long long exp) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int min_val = *min_element(a.begin(), a.end());
        int cnt = count(a.begin(), a.end(), min_val);
        
        long long ans = 1;
        ans = (ans * n) % MOD;
        ans = (ans * (n - 1)) % MOD;
        ans = (ans * binpow(2, cnt)) % MOD;
        
        cout << ans << endl;
    }
    
    return 0;
}