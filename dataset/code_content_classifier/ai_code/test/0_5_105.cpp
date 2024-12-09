#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), m(n);
        vector<pair<int, int>> idx(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> m[i];
            idx[i].first = a[i] + b[i];
            idx[i].second = i;
        }

        sort(idx.begin(), idx.end());

        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (a[idx[i].second] + b[idx[i].second] == a[idx[i - 1].second] + b[idx[i - 1].second]) {
                ans++;
            }
        }

        cout << ans << endl;

        for (int i = 0; i < n; i++) {
            cout << min(a[i], m[i]) << " " << m[i] - min(a[i], m[i]) << endl;
        }
    }

    return 0;
}