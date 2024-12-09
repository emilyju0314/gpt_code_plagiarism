#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    
    return primes;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<int> primes = sieve(10000);
    
    int m;
    cin >> m;
    
    while (m--) {
        int li, ri;
        cin >> li >> ri;
        
        vector<bool> is_prime(ri - li + 1, true);
        
        for (int p : primes) {
            if (p * p > ri) break;
            
            int start = max(p * p, (li + p - 1) / p * p);
            
            for (int i = start; i <= ri; i += p) {
                is_prime[i - li] = false;
            }
        }
        
        int answer = 0;
        for (int i = li; i <= ri; i++) {
            if (is_prime[i - li] && count(x.begin(), x.end(), i) > 0) {
                answer += count(x.begin(), x.end(), i);
            }
        }
        
        cout << answer << endl;
    }
    
    return 0;
}