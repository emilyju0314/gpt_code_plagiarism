#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;

    vector<pair<int, int>> cars(n);
    for (int i = 0; i < n; i++) {
        int c, v;
        cin >> c >> v;
        cars[i] = make_pair(c, v);
    }

    vector<int> gas_stations(k);
    for (int i = 0; i < k; i++) {
        cin >> gas_stations[i];
    }

    sort(gas_stations.begin(), gas_stations.end());

    int min_price = -1;
    for (auto car : cars) {
        int c = car.first;
        int v = car.second;

        int time = 0; // Time taken to reach cinema
        int fuel = v; // Fuel remaining in the tank

        // Check if it's possible to reach cinema with this car
        bool can_reach_cinema = true;
        for (int i = 0; i < k; i++) {
            int distance = gas_stations[i] - (i == 0 ? 0 : gas_stations[i-1]);

            // Check if faster mode can be used
            int normal_time = (distance * 2);
            int accelerated_time = (distance * 1);

            if (normal_time <= t) {
                time += normal_time;
                fuel -= distance;
            } else if (accelerated_time <= t) {
                time += accelerated_time;
                fuel -= (distance * 2);
            } else {
                can_reach_cinema = false;
                break;
            }

            if (fuel < 0) {
                can_reach_cinema = false;
                break;
            }
        }

        // Last segment from last gas station to cinema
        int last_distance = s - (k > 0 ? gas_stations.back() : 0);
        int last_normal_time = (last_distance * 2);
        int last_accelerated_time = (last_distance * 1);

        if (last_normal_time <= t) {
            time += last_normal_time;
            fuel -= last_distance;
        } else if (last_accelerated_time <= t) {
            time += last_accelerated_time;
            fuel -= (last_distance * 2);
        } else {
            can_reach_cinema = false;
        }

        if (time <= t && can_reach_cinema) {
            if (min_price == -1 || c < min_price) {
                min_price = c;
            }
        }
    }

    cout << min_price << endl;

    return 0;
}