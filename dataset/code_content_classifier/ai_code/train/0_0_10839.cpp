#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, s, k;
        cin >> n >> s >> k;

        set<int> closedRestaurants;
        for (int j = 0; j < k; j++) {
            int closedFloor;
            cin >> closedFloor;
            closedRestaurants.insert(closedFloor);
        }

        vector<int> distances;
        int minDist = n;

        for (int j = 0; j <= n; j++) {
            if (closedRestaurants.find(j) == closedRestaurants.end() && j != s) {
                int dist = abs(j - s);
                distances.push_back(dist);
                minDist = min(minDist, dist);
            }
        }

        cout << minDist << endl;
    }

    return 0;
}