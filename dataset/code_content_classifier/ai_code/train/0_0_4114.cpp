#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> coords; // Store the centers of magnets

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        coords.push_back({(x1 + x2) / 2, (y1 + y2) / 2}); // Calculate the center of each magnet
    }

    sort(coords.begin(), coords.end()); // Sort the center coordinates

    long long ans = 1e18;

    for (int i = 0; i <= k; i++) {
        for (int j = n - 1; j >= k; j--) {
            long long dx = coords[j].first - coords[i].first;
            vector<long long> dy;

            for (int l = i; l <= j; l++) {
                dy.push_back(coords[l].second);
            }

            sort(dy.begin(), dy.end());

            for (int l = 0; l + k <= j - i; l++) {
                ans = min(ans, dx * (dy[l + k] - dy[l]));
            }
        }
    }

    cout << ans << endl;

    return 0;
}