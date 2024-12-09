#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> operations(m);
    for (int i = 0; i < m; i++) {
        cin >> operations[i].first >> operations[i].second;
    }

    vector<int> perm(n + 1);
    vector<bool> fixed(n + 1, false);
    for (int i = 1; i <= n; i++) {
        perm[i] = i;
    }

    for (int i = m - 1; i >= 0; i--) {
        if (!fixed[operations[i].first]) {
            fixed[operations[i].first] = true;
            perm.erase(perm.begin() + operations[i].first);
            perm.insert(perm.begin(), operations[i].first);
        } else {
            if (perm[0] != operations[i].first) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!fixed[i]) {
            perm.erase(perm.begin() + i);
            perm.insert(perm.begin(), i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << perm[i] << " ";
    }

    return 0;
}