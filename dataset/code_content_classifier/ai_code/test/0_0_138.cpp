#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> prefix_sum(m+1, 0);
    for(int i = 1; i <= m; i++) {
        prefix_sum[i] = prefix_sum[i-1] + b[i-1];
    }
    
    while(q--) {
        int k;
        cin >> k;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int lb = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if(lb < m) {
                ans = max(ans, prefix_sum[m] - prefix_sum[lb] + a[i]);
            }
            ans = max(ans, a[i]);
        }
        
        cout << ans + k << endl;
    }
    
    return 0;
}