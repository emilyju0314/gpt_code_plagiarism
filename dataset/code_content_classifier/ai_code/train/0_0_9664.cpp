#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<pair<int, int>> chestCoords(p + 1); // Coordinates of each chest type
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int chestType;
            cin >> chestType;
            chestCoords[chestType] = {i, j};
        }
    }

    int totalDistance = 0;
    pair<int, int> currPos = {0, 0}; // Starting position
    for (int i = 1; i <= p; i++) {
        totalDistance += abs(currPos.first - chestCoords[i].first) + abs(currPos.second - chestCoords[i].second);
        currPos = chestCoords[i];
    }

    cout << totalDistance << endl;

    return 0;
}