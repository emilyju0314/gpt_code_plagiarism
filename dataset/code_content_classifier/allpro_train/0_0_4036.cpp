#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    long long t;
    cin >> n >> t >> a >> b >> c;

    vector<pair<int, int>> sensors;
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++) {
            sensors.push_back({a + i, b + j});
        }
    }

    sort(sensors.begin(), sensors.end());

    vector<char> steps;
    int x = 1, y = 1;
    bool possible = true;

    for(int i = 0; i < 2*n - 2; i++) {
        long long min_dist = LLONG_MAX;
        pair<int, int> closest_sensor = {-1, -1};

        for(auto sensor : sensors) {
            long long dist = abs(sensor.first - x) + abs(sensor.second - y);

            if(dist < min_dist) {
                min_dist = dist;
                closest_sensor = sensor;
            }
        }

        if(t - min_dist < 0) {
            possible = false;
            break;
        }

        if(closest_sensor.first < x) {
            steps.push_back('U');
            y += 1;
        } else {
            steps.push_back('R');
            x += 1;
        }

        for(auto& sensor : sensors) {
            sensor.second -= 1;
        }

        t -= min_dist;
    }

    if(possible) {
        for(auto step : steps) {
            cout << step;
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}