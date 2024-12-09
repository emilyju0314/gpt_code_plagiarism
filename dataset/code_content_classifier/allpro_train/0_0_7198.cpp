#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> antennas(n);
    for (int i = 0; i < n; i++) {
        cin >> antennas[i].x >> antennas[i].y;
    }

    int m;
    cin >> m;

    for (int query = 0; query < m; query++) {
        vector<long long> distances(n);
        for (int i = 0; i < n; i++) {
            cin >> distances[i];
        }

        sort(distances.begin(), distances.end());

        vector<Point> possibleLocations;
        for (int x = 0; x <= 100000000; x++) {
            for (int y = 0; y <= 100000000; y++) {
                bool valid = true;
                for (int i = 0; i < n; i++) {
                    long long calcDistance = (x - antennas[i].x) * (x - antennas[i].x) + (y - antennas[i].y) * (y - antennas[i].y);
                    if (find(distances.begin(), distances.end(), calcDistance) == distances.end()) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    possibleLocations.push_back({x, y});
                }
            }
        }

        cout << possibleLocations.size() << " ";
        for (int i = 0; i < possibleLocations.size(); i++) {
            cout << possibleLocations[i].x << " " << possibleLocations[i].y << " ";
        }
        cout << endl;
    }

    return 0;
}