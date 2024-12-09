#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, double>> plants(n);
    for (int i = 0; i < n; i++) {
        cin >> plants[i].first >> plants[i].second;
    }

    map<int, double> borders;
    for (int i = 1; i <= m; i++) {
        borders[i] = plants[i-1].second;
    }

    // Initialize the count of replanted plants
    int replanted = 0;

    for (int i = 0; i < n; i++) {
        if (plants[i].first != borders.begin()->first) {
            // Calculate the distance to the border for this plant
            double dist = abs(plants[i].second - borders.begin()->second);
            
            // Set the new border for this species
            borders[plants[i].first] = plants[i].second;

            // Update the count of replanted plants
            replanted++;
            
            // Update the border map to maintain the order
            for (auto it = borders.begin(); it != borders.end(); it++) {
                it->second = min(it->second, borders.begin()->second + (it->first - borders.begin()->first)*dist);
            }
        } else {
            borders.erase(borders.begin());
        }
    }

    cout << replanted << endl;

    return 0;
}