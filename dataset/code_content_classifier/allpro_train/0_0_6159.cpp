#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        int ans = 0;
        
        for (int i = 0; i <= k; i++) {
            int sum = 0;
            for (int j = i-1; j < n; j += k) {
                if (j >= 0) {
                    sum += a[j];
                    if (sum <= p) {
                        ans = max(ans, j-i+1);
                    }
                }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}