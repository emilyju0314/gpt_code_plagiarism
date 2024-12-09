#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n);
    vector<int> maintenance(n, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        trains[i] = make_pair(x, y);
    }

    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if (op == 1) {
            maintenance[k] = trains[k].second;
        } else {
            maintenance[k] = 0;
        }

        int current_maintenance = 0;
        for (int j = 0; j < n; j++) {
            current_maintenance = max(current_maintenance, maintenance[j]);
        }

        cout << current_maintenance << endl;
    }

    return 0;
}