#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        trains[i] = make_pair(x, y);
    }

    unordered_map<int, int> inMaintenance;
    int totalMaintenance = 0;

    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if (op == 1) {
            inMaintenance[k] = trains[k].second;
            totalMaintenance++;
        } else {
            inMaintenance[k] = 0;
            totalMaintenance--;
        }

        cout << totalMaintenance << endl;
    }

    return 0;
}