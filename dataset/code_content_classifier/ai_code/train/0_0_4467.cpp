#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> roads(n, vector<int>(n, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cin >> roads[i][j];
        }
    }

    vector<int> ans(n, 0);
    for (int i = 1; i < n; i++) {
        int total_perishability = 0;

        // Calculate the total perishability of all routes to city i
        for (int j = 1; j < n; j++) {
            int min_perishability = INT_MAX;

            // Calculate the minimum perishability for each route to city i
            for (int k = j; k < n; k++) {
                int road_perishability = roads[k][j-1];
                min_perishability = min(min_perishability, road_perishability);
            }

            total_perishability += min_perishability;
        }

        ans[i] = total_perishability;
    }

    for (int i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}