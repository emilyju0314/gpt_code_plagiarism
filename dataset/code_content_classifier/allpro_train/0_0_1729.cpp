#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> bridges(N - 1);

    for (int i = 0; i < N - 1; i++) {
        int p, w;
        cin >> p >> w;

        bridges[i] = make_pair(p, w);
    }

    // Initialize variables to store maximum cycle length and total distance
    int maxCycle = 0, totalDistance = 0;

    // Calculate total distance and initialize maxCycle with it
    for (int i = 0; i < N - 1; i++) {
        totalDistance += bridges[i].second;
        if (i == N - 2) {
            maxCycle = totalDistance;
        }
    }

    // Loop through bridges to find the maximum cycle length
    for (int i = 0; i < N - 1; i++) {
        // Sum of distances on both sides of the removed bridge
        int cycleLength = totalDistance - bridges[i].second;

        // Update maxCycle if a longer cycle is found
        maxCycle = max(maxCycle, cycleLength);
    }

    cout << maxCycle << endl;

    return 0;
}