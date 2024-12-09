#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> constraints(n, {0, 229});

    for (int i = 0; i < m; i++) {
        int l, r, q;
        cin >> l >> r >> q;
        for (int j = l-1; j < r; j++) {
            constraints[j].first = max(constraints[j].first, q);
            constraints[j].second = min(constraints[j].second, q);
        }
    }

    for (int i = 0; i < n; i++) {
        if (constraints[i].first < constraints[i].second) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << constraints[i].first << " ";
    }
    cout << endl;

    return 0;
}