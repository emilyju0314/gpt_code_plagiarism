#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n);
    vector<int> running(n, 0);
    vector<int> in_maintenance(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> trains[i].first >> trains[i].second;
    }

    int total_trains = 0;
    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--;

        if (op == 1) {
            running[k] = trains[k].first;
            total_trains++;
        } else {
            total_trains -= in_maintenance[k];
            running[k] = 0;
        }

        cout << total_trains << endl;

        for (int j = 0; j < n; j++) {
            if (running[j] > 0) {
                running[j]--;
                if (running[j] == 0) in_maintenance[j] = trains[j].second;
            } else if (in_maintenance[j] > 0) {
                in_maintenance[j]--;
                if (in_maintenance[j] == 0) running[j] = trains[j].first;
            }
        }
    }

    return 0;
}