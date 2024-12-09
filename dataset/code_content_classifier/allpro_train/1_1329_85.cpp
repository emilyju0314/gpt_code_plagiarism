#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> notes(2 * n + 10, 0);
        for (auto x : a) {
            if (notes[x]) {
                notes[x+1] = 1;
            } else {
                notes[x] = 1;
            }
        }
        int ans = 0;
        for (auto x : notes) ans += x;
        cout << ans << endl;
    }
    

    return 0; 
}

