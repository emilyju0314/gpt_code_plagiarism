#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> primes;
        primes.push_back(1);
        
        for(int i = 1; i * i <= n; i++) {
            primes.push_back(i);
            if(i * i != n) primes.push_back(n / i);
        }
        
        vector<int> dp(primes.size());
        
        int ans = 0;
        for(int i = primes.size()-1; i >= 1; i--) {
            int l = primes[i-1] + 1;
            int r = primes[i];
            if(l > r) continue;
            dp[i] = 1ll * (r - l + 1) * (r - l + 2) / 2;
            for(int j = 2 * primes[i]; j <= n; j += primes[i]) {
                dp[i] -= dp[j];
            }
            ans += dp[i] * gcd(primes[i], n);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}