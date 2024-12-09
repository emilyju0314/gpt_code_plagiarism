#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);

    vector<pair<int, int>> operations;
    vector<pair<int, pair<int, int>>> type1;

    for (int i = 0; i < m; i++) {
        int t, l, r, d;
        cin >> t >> l >> r >> d;
        if (t == 1) {
            type1.push_back({l, {r, d}});
        } else {
            operations.push_back({l, r});
        }
    }

    vector<int> max_values(n, 0);
    for (int i = 0; i < operations.size(); i++) {
        for (int j = operations[i].first - 1; j < operations[i].second; j++) {
            max_values[j] = max(max_values[j], operations[i].second);
        }
    }

    for (pair<int, pair<int, int>> t : type1) {
        for (int j = t.first - 1; j < t.second.first; j++) {
            a[j] += t.second.second;
        }
    }

    for (int i = 0; i < n; i++) {
        if (max_values[i] < a[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}