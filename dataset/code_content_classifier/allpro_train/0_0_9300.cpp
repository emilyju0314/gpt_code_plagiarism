#include <iostream>
#include <vector>

#define MOD 1000000000

using namespace std;

long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long a = 0, b = 1, c;
    
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    
    return b;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            a[x-1] = v;
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            
            long long sum = 0;
            for (int j = l-1; j < r; j++) {
                sum = (sum + (long long)a[j] * fib(j-l+1)) % MOD;
            }
            cout << sum << endl;
        } else if (t == 3) {
            int l, r, d;
            cin >> l >> r >> d;
            
            for (int j = l-1; j < r; j++) {
                a[j] += d;
            }
        }
    }
    
    return 0;
}