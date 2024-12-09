#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9+7;

int fib(int x) {
    if(x == 1 || x == 2) return 1;
    int a = 1, b = 1, c;
    for(int i = 3; i <= x; i++) {
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        int t, l, r, x;
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> x;
            for(int j = l-1; j < r; j++) {
                a[j] += x;
            }
        } else {
            int ans = 0;
            for(int j = l-1; j < r; j++) {
                ans = (ans + fib(a[j])) % MOD;
            }
            cout << ans << endl;
        }
    }

    return 0;
}