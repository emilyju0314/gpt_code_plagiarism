#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<pair<int, pair<int, pair<int, int>>> ops;

    for (int i = 0; i < m; i++) {
        int t, l, r, d;
        cin >> t >> l >> r >> d;
        ops.push_back({t, {l, {r, d}});
    }

    for (int i = m - 1; i >= 0; i--) {
        int t = ops[i].first;
        int l = ops[i].second.first - 1;
        int r = ops[i].second.second.first - 1;
        int val = ops[i].second.second.second;

        if (t == 1) {
            for (int j = l; j <= r; j++) {
                a[j] += val;
            }
        } else {
            int max_val = a[l];
            for (int j = l + 1; j <= r; j++) {
                max_val = max(max_val, a[j]);
            }
            if (max_val != val) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}