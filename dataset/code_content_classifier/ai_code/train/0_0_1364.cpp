#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, char>> cities;
    for(int i = 0; i < n; i++) {
        int coord;
        char type;
        cin >> coord >> type;
        cities.push_back(make_pair(coord, type));
    }

    vector<long long> distances; // to store the distances between disputed cities
    long long totalDistance = 0;
    for(int i = 1; i < n; i++) {
        if(cities[i].second == 'P') {
            long long distance = abs(cities[i].first - cities[i-1].first);
            distances.push_back(distance);
            totalDistance += distance;
        }
    }

    long long minTotalDistance = 1e18; // initialized with a large value
    long long currDistance = 0;
    for(int i = 0; i < distances.size(); i++) {
        currDistance += distances[i];
        minTotalDistance = min(minTotalDistance, totalDistance - 2 * currDistance + distances[i]);
    }

    cout << minTotalDistance << endl;

    return 0;
}