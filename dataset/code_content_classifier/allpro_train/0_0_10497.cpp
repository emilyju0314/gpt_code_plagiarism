#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int cnt = n;
    vector<pair<int, int>> operations;
    
    for(int i=1; i<=n; i++) {
        operations.push_back({n+i, i});
    }

    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        int k = cnt+1;
        operations.push_back({k, k-1});
        for(int j=l; j<=r; j++) {
            operations.push_back({k, a[j-1]});
        }
        cnt++;
    }

    cout << cnt << endl;
    for(auto opr : operations) {
        cout << opr.first << " " << opr.second << endl;
    }

    return 0;
}