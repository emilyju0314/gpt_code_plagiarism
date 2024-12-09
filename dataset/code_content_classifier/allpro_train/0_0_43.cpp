#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, pair<int, int>>> roads;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        roads.push_back({w, {u, v}});
    }

    sort(roads.begin(), roads.end());

    vector<int> prefix_max(m + 1, -1);
    vector<int> suffix_max(m + 1, -1);

    for (int i = 0; i < m; i++) {
        prefix_max[i + 1] = max(prefix_max[i], roads[i].first);
    }

    for (int i = m - 1; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i + 1], roads[i].first);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int res = -1;
        if (suffix_max[l] != -1) {
            res = suffix_max[l];
        }
        if (prefix_max[r] != -1) {
            res = (res == -1) ? prefix_max[r] : min(res, prefix_max[r]);
        }

        cout << res << endl;
    }

    return 0;
}