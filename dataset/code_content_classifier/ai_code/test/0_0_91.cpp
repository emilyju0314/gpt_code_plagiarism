#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = a[i];
            for (int j = i; j < n; j++) {
                if (j != i) {
                    sum += a[j];
                }
                int min_val = a[i];
                for (int k = i; k <= j; k++) {
                    min_val = min(min_val, a[k]);
                }
                ans = (ans + min_val) % MOD;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}