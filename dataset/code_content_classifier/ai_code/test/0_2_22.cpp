#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n);
    unordered_map<int, int> inMaintenance;

    for(int i = 0; i < n; i++) {
        cin >> trains[i].first >> trains[i].second;
    }

    int maintenanceCount = 0;

    for(int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if(op == 1) {
            inMaintenance[k] = trains[k].second;
            maintenanceCount++;
        } else {
            inMaintenance.erase(k);
            maintenanceCount--;
        }

        cout << maintenanceCount << endl;
    }

    return 0;
}