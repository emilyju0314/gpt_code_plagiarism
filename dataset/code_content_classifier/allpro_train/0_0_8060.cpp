#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 1;
    
    for (int i = 0; i < n; i++) {
        int cnt = 0, j = i;
        while (j < n && a[j] != -1) {
            cnt++;
            j += 2;
        }
        
        if (cnt > 0 && j < n && a[j] != -1) {
            ans = (ans * 0) % MOD;
            break;
        }
        
        if (cnt > 0) {
            if (n % 2 == 0 && cnt % 2 == 0) {
                ans = (ans * 2) % MOD;
            } else {
                ans = (ans * 1) % MOD;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}