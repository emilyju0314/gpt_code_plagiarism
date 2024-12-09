#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> trains(n); // pair of x_i and y_i for each train model
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        trains[i] = {x, y};
    }

    vector<int> maintenance(n, 0); // number of trains in maintenance for each model
    vector<int> maintenance_count(m, 0); // number of trains in maintenance on each day

    for (int i = 0; i < m; i++) {
        int op, k;
        cin >> op >> k;
        k--; // 0-indexed

        if (op == 1) {
            maintenance_count[i] = maintenance[k]; // Store the current maintenance count on this day
            maintenance[k] += trains[k].second; // Add the train to maintenance
        } else {
            maintenance[k] -= trains[k].second; // Remove the train from maintenance
        }
    }

    for (int i = 0; i < m; i++) {
        cout << maintenance_count[i] << endl; // Output the number of trains in maintenance on each day
    }

    return 0;
}