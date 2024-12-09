#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int concat(int x, int y) {
    int res = y;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + concat(a[i], a[j])) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}