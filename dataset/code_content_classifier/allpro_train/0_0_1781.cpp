#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    vector<int> towers(m);

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    sort(cities.begin(), cities.end());
    sort(towers.begin(), towers.end());

    int minDistance = 0;

    for (int i = 0; i < n; i++) {
        int minCityDistance = INT_MAX;

        for (int j = 0; j < m; j++) {
            minCityDistance = min(minCityDistance, abs(cities[i] - towers[j]));
        }

        minDistance = max(minDistance, minCityDistance);
    }

    cout << minDistance << endl;

    return 0;
}