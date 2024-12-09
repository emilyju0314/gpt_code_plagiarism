#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<pair<int, int>> roads(m);
        unordered_map<int, vector<int>> cityToRoads;
        vector<int> companyAssignments(m);

        for (int i = 0; i < m; i++) {
            cin >> roads[i].first >> roads[i].second;
            cityToRoads[roads[i].first].push_back(i);
            cityToRoads[roads[i].second].push_back(i);
        }

        int company = 1;

        for (int i = 1; i <= n; i++) {
            if (cityToRoads[i].size() > 2 * k) {
                cout << "0 0 0 0 0 0 ";
                for (int j = 0; j < m - 6; j++) {
                    cout << "0 ";
                }
                cout << endl;
                continue;
            }

            for (int roadIdx : cityToRoads[i]) {
                companyAssignments[roadIdx] = company;
                company = company % 100500 + 1;
            }
        }

        for (int i = 0; i < m; i++) {
            cout << companyAssignments[i] << " ";
        }
        cout << endl;
    }

    return 0;
}