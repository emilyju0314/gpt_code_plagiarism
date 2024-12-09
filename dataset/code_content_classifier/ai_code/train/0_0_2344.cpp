#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> initial_positions(m);
    vector<pair<int, int>> final_positions(m);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        initial_positions[i] = make_pair(x, y);
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        final_positions[i] = make_pair(x, y);
    }

    vector<pair<pair<int, int>, pair<int, int>>> operations;

    int total_operations = 0;
    for(int i = 0; i < m; i++) {
        int x_diff = final_positions[i].first - initial_positions[i].first;
        int y_diff = final_positions[i].second - initial_positions[i].second;

        while(x_diff != 0) {
            int sign = x_diff > 0 ? 1 : -1;
            operations.push_back({initial_positions[i], {initial_positions[i].first + sign, initial_positions[i].second}});
            initial_positions[i].first += sign;
            x_diff -= sign;
            total_operations++;
        }

        while(y_diff != 0) {
            int sign = y_diff > 0 ? 1 : -1;
            operations.push_back({initial_positions[i], {initial_positions[i].first, initial_positions[i].second + sign}});
            initial_positions[i].second += sign;
            y_diff -= sign;
            total_operations++;
        }
    }

    cout << total_operations << endl;
    for(auto op : operations) {
        cout << op.first.first << " " << op.first.second << " " << op.second.first << " " << op.second.second << endl;
    }

    return 0;
}