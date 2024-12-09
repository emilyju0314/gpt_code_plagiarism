#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> l, r;
    vector< pair<int, int> > v(n);

    for (auto &[m, n] : v) {
        cin >> m >> n;
        l.push_back(m);
        r.push_back(n);
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int ans = n - 1;

    for (auto [m, n] : v) {
        int left = lower_bound(r.begin(), r.end(), m) - r.begin();
        int right = l.end() - upper_bound(l.begin(), l.end(), n);

        ans = min(ans, left + right);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}