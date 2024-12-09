#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<long long> prefix_max(m);
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j + 1 < n && a[j + 1] <= b[i]) {
            j++;
        }
        prefix_max[i] = (j > 0 ? prefix_max[i - 1] : 0) + a[j];
    }
    
    while (q--) {
        int k;
        cin >> k;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            int pos = upper_bound(b.begin(), b.end(), b[i] + k) - b.begin() - 1;
            if (pos >= 0) {
                ans = max(ans, prefix_max[pos] + 1LL * (m - pos - 1) * (b[i] + k));
            } else {
                ans = max(ans, 1LL * m * (b[i] + k));
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}