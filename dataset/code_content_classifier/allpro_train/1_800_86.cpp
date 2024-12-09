#include "bits/stdc++.h"

#define ll long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(2));
    bool sw = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    for(int i = 0; i < n; i++) {
        bool flag = 0;
        for (int j = 0; j < n; j++){
            if (i != j && abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]) > k) {
                flag = 1;
                break;
            }
        }
        if(!flag){
            sw = 0;
            break;
        }
    }
    if(!sw)
        cout << 1 << endl;
    else
        cout << -1 << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}