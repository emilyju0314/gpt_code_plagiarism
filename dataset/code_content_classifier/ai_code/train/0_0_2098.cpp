#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        vector<int> p;
        for (int i = 0; i < k; i++) {
            p.push_back(i);
        }
        for (int i = k-2; i > 0; i--) {
            p.push_back(i);
        }

        bool possible = true;
        int x = 0;
        int t = 0;
        while (x < n) {
            if (d[x] + p[t % (2 * k)] > l) {
                possible = false;
                break;
            }
            int time_to_island = n - x; // remaining distance to reach island
            int time_to_next_tide_change = k - t % k; // time to next tide change
            int max_depth_reached = d[x] + p[t % (2 * k)] + time_to_next_tide_change; // max depth allowed until next tide change

            // check if Koa can reach the island in current tide phase
            if (max_depth_reached + time_to_island <= l) {
                // reached the island
                x = n;
            } else {
                // unable to reach the island in current tide phase, swim further
                x++;
            }
            t++;
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}