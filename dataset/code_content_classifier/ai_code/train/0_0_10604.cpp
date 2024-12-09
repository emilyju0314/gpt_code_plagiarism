#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    
    int a = 1, b = 1;
    for (int i = 3; i <= n; i++) {
        int c = (a + b) % MOD;
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
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 1) {
            int f = fibonacci(l);
            for (int j = l; j <= r; j++) {
                a[j - 1] = (a[j - 1] + f) % MOD;
            }
        } else {
            int sum = 0;
            for (int j = l; j <= r; j++) {
                sum = (sum + a[j - 1]) % MOD;
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}