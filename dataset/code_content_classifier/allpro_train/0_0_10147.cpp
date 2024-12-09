#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cities(n);
    vector<int> c(n), k(n);

    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<int> power_stations;
    vector<pair<int, int>> connections;

    long long total_cost = 0;

    // Calculate the cost of building power stations and connect cities
    for (int i = 0; i < n; i++) {
        total_cost += c[i];
        power_stations.push_back(i + 1);

        long long min_connection_cost = LLONG_MAX;
        int target_city = -1;

        for (int j = 0; j < n; j++) {
            if (j != i) {
                long long connection_cost = (k[i] + k[j]) * (abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second));
                if (connection_cost < min_connection_cost) {
                    min_connection_cost = connection_cost;
                    target_city = j;
                }
            }
        }

        if (target_city != -1) {
            connections.push_back(make_pair(i + 1, target_city + 1));
            total_cost += min_connection_cost;
        }
    }

    // Output the minimum amount of yen needed
    cout << total_cost << endl;

    // Output the number of power stations to be built
    cout << power_stations.size() << endl;
    for (int station : power_stations) {
        cout << station << " ";
    }
    cout << endl;

    // Output the number of connections to be made
    cout << connections.size() << endl;
    for (auto connection : connections) {
        cout << connection.first << " " << connection.second << endl;
    }

    return 0;
}