#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int d, n, m;
    cin >> d >> n >> m;

    vector<pair<int, int>> gas_stations;
    for (int i = 0; i < m; i++) {
        int xi, pi;
        cin >> xi >> pi;
        gas_stations.push_back({xi, pi});
    }

    sort(gas_stations.begin(), gas_stations.end());

    gas_stations.push_back({d, 0});

    int position = 0, tank = n, cost = 0;
    int index = 0;

    while (index < m+1) {
        int next_station = gas_stations[index].first;
        int fuel_needed = next_station - position;

        if (fuel_needed > tank) {
            int fill_up = fuel_needed - tank;
            if (fill_up > n) {
                cout << -1 << endl;
                return 0;
            }
            cost += fill_up * gas_stations[index-1].second;
            tank = n;
        }

        tank -= fuel_needed;
        position = next_station;
        index++;
    }

    cout << cost << endl;

    return 0;
}