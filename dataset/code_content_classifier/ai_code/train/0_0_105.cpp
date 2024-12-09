#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n || j < m) {
        if(i < n && (j == m || a[i] < b[j])) {
            if(a[i] == 0 || a[i] <= k) {
                ans.push_back(a[i]);
                if(a[i] == 0) {
                    k++;
                }
                i++;
            } else {
                cout << "-1\n";
                return;
            }
        } else {
            if(b[j] == 0 || b[j] <= k) {
                ans.push_back(b[j]);
                if(b[j] == 0) {
                    k++;
                }
                j++;
            } else {
                cout << "-1\n";
                return;
            }
        }
    }
    
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}