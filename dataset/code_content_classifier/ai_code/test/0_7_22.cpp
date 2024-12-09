#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n); // pair of (working days, maintenance days) for each train model
    vector<int> daysInMaintenance(n, 0); // number of days each train model is in maintenance
    vector<int> daysUntilNextMaintenance(n, 0); // number of days until each train model goes into maintenance

    for (int i = 0; i < n; i++) {
        cin >> trains[i].first >> trains[i].second;
        daysUntilNextMaintenance[i] = trains[i].first;
    }

    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--; // adjusting to 0-based indexing

        if (op == 1) {
            daysInMaintenance[k] = 0; // Reset days in maintenance when a train of model k is added
            daysUntilNextMaintenance[k] = trains[k].first;
            for (int j = 0; j < n; j++) {
                if (j != k && daysInMaintenance[j] > 0) {
                    daysInMaintenance[j]++;
                    if (daysInMaintenance[j] == trains[j].second) {
                        daysInMaintenance[j] = 0;
                        daysUntilNextMaintenance[j] = trains[j].first;
                    }
                }
            }
        } else {
            cout << daysInMaintenance[k] << endl; // Output number of days the removed train was in maintenance
        }
    }

    return 0;
}