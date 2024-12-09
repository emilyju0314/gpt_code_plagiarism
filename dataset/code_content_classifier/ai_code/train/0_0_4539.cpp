#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int fibonacci(int n) {
    vector<int> fib(n + 1);
    fib[1] = 1;
    fib[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    
    return fib[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 1) {
            int fib_num = fibonacci(l+1);
            for (int j = l; j <= r; j++) {
                a[j] = (a[j] + fib_num) % MOD;
            }
        } else if (type == 2) {
            int sum = 0;
            for (int j = l; j <= r; j++) {
                sum = (sum + a[j]) % MOD;
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}