#include <iostream>

using namespace std;

int power(int x, unsigned int y, int p) {
    int res = 1;      // Initialize result
    
    x = x % p;  // Update x if it is more than or equal to p
    
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
        
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    // Calculate u/d = n!/(2^k * (n-k)!) modulo q
    long long u = 1;
    long long d = 1;
    
    for(int i = n; i >= n-k+1; i--) {
        u = (u * i) % q;
    }
    
    for(int i = 1; i <= k; i++) {
        d = (d * 2) % q;
    }
    
    long long inv_d = power(d, q-2, q); // Calculate d^(q-2) modulo q
    
    long long result = (u * inv_d) % q;
    
    cout << result << endl;
    
    return 0;
}