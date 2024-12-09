#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> positions(n);
    for(int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    // Sort the positions to simplify the calculation
    sort(positions.begin(), positions.end());

    int min_moves = 0;
    for(int i = 0; i < n; i++) {
        int clockwise_moves = max(positions[i] - 1, m - positions[i]) + 1;
        min_moves = max(min_moves, clockwise_moves);
    }

    cout << min_moves << endl;

    return 0;
}