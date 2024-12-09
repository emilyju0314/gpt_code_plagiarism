#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int f, T, t0;
    cin >> f >> T >> t0;

    int a1, t1, p1;
    cin >> a1 >> t1 >> p1;

    int a2, t2, p2;
    cin >> a2 >> t2 >> p2;

    int min_cost = INT_MAX;

    for (int i = 0; i <= f; i += a1) {
        int bytes_left = f - i;
        int remaining_time = T - i*t0;

        // Check if first package is used completely
        int cost = i/a1 * p1;
        if (bytes_left <= 0) {
            min_cost = min(min_cost, cost);
            continue;
        }

        // Calculate the number of bytes to download using second package
        int bytes_second = min(bytes_left, a2);
        int time_second = bytes_second * t2;

        // Check if second package is used completely
        if (bytes_second < a2) {
            int cost_second = cost + p2;
            min_cost = min(min_cost, cost_second);
            continue;
        }

        // Check if download is possible within time limit
        if (i*t0 + time_second <= T) {
            min_cost = min(min_cost, cost);
        }
    }

    if (min_cost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

    return 0;
}