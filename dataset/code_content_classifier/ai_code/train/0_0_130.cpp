#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;

    vector<pair<int, int>> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i].first >> cars[i].second;
    }

    vector<int> gas_stations(k);
    for (int i = 0; i < k; i++) {
        cin >> gas_stations[i];
    }

    sort(gas_stations.begin(), gas_stations.end());

    int result = -1;
    for (int i = 0; i < n; i++) {
        int price = cars[i].first;
        int tank_capacity = cars[i].second;

        int time_taken = 0;
        int current_position = 0;
        int current_fuel = tank_capacity;

        for (int j = 0; j < k; j++) {
            int dist_to_next_station = gas_stations[j] - current_position;
            int dist_to_cinema = s - gas_stations[j];

            int time_to_next_station = dist_to_next_station / 2;
            if (current_fuel < time_to_next_station) {
                int deficit = time_to_next_station - current_fuel;
                time_taken += deficit;
                current_fuel = tank_capacity;
            }

            current_fuel -= time_to_next_station;
            current_position = gas_stations[j];

            time_taken += time_to_next_station;

            current_fuel = min(current_fuel + dist_to_next_station, tank_capacity);

            time_taken += dist_to_next_station / (current_fuel >= 1 ? 1 : 2);
            current_position = gas_stations[j];
        }

        int dist_to_cinema = s - current_position;
        if (dist_to_cinema > 0) {
            int time_to_cinema = dist_to_cinema / (current_fuel >= 1 ? 1 : 2);
            if (time_taken + time_to_cinema <= t) {
                if (result == -1 || price < result) {
                    result = price;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}