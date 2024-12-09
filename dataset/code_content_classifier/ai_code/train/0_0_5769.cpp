#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long long power(int x, int y, int p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        
        y = y >> 1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        vector<int> primes;
        for (int i = 2; i*i <= x; i++) {
            if (x % i == 0) {
                primes.push_back(i);
                while (x % i == 0)
                    x /= i;
            }
        }
        if (x > 1)
            primes.push_back(x);
        
        long long ans = 1;
        for (int prime : primes) {
            int cnt = 0;
            int temp = y;
            while (temp % prime == 0) {
                cnt++;
                temp /= prime;
            }
            ans = (ans * power(prime, cnt+1, MOD)) % MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}