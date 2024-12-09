#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Create a vector of flights
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    // Initialize a vector to store minimum number of flights needed to reach each city
    vector<int> min_flights(n + 1, INT_MAX);
    min_flights[1] = 0;

    // Bellman-Ford algorithm to find minimum number of flights needed
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ai = flights[j][0];
            int bi = flights[j][1];
            int di = flights[j][2];

            if (min_flights[ai] == INT_MAX) continue;
            if (min_flights[ai] >= di) {
                min_flights[bi] = min(min_flights[bi], min_flights[ai] + 1);
            }
        }
    }

    // Check if it is possible to reach city n
    if (min_flights[n] == INT_MAX) {
        cout << "Impossible" << endl;
    } else {
        cout << min_flights[n] << endl;
    }

    return 0;
}