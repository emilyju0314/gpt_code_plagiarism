#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> maintenance(n);
    for (int i = 0; i < n; i++) {
        cin >> maintenance[i];
    }

    vector<vector<int>> data_centers(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> data_centers[i][0] >> data_centers[i][1];
    }

    vector<set<int>> conflicting_data_centers(n + 1);
    for (int i = 0; i < m; i++) {
        conflicting_data_centers[data_centers[i][0]].insert(data_centers[i][1]);
        conflicting_data_centers[data_centers[i][1]].insert(data_centers[i][0]);
    }

    int min_data_centers = n;
    set<int> result;
    for (int i = 1; i <= n; i++) {
        set<int> conflicting_hours;
        for (int j : conflicting_data_centers[i]) {
            if ((maintenance[j-1] + 1) % h == maintenance[i-1]) {
                conflicting_hours.insert(j);
            }
        }

        if (conflicting_hours.size() < min_data_centers) {
            min_data_centers = conflicting_hours.size();
            result = conflicting_hours;
            result.insert(i);
        }
    }

    cout << min_data_centers << endl;
    for (int dc : result) {
        cout << dc << " ";
    }
    cout << endl;

    return 0;
}