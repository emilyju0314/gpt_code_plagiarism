#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int r, s, p;
    cin >> r >> s >> p;

    vector<pair<int, int>> positions(p); // Store initial positions of passengers

    for (int i = 0; i < p; i++) {
        int row, seat;
        cin >> row >> seat;
        positions[i] = make_pair(row, seat);
    }

    int totalSteps = 0;

    for (int i = 0; i < p; i++) {
        int row = positions[i].first;
        int seat = positions[i].second;

        // Calculate steps to get to the aisle
        int toAisle = min(seat - 1, 2 * s - seat);

        // Calculate steps to get to the emergency exit
        int toExit = r - row;

        // Update total steps
        totalSteps += toAisle + toExit;
    }

    cout << totalSteps << endl;

    return 0;
}