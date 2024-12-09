#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n);
    vector<int> status(n, -1); // -1: not in department, 0: in maintenance, 1: in work

    for (int i = 0; i < n; i++) {
        cin >> trains[i].first >> trains[i].second;
    }

    int totalMaint = 0;
    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if (op == 1) {
            status[k] = 1;
            totalMaint += status[k] == 0 ? 1 : 0;
        } else {
            status[k] = 0;
            totalMaint -= status[k] == 1 ? 1 : 0;
        }

        cout << totalMaint << endl;
    }

    return 0;
}