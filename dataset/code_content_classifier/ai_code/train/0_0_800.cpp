#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }

        bool possible = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = abs(points[i].first - points[j].first);
                int dy = abs(points[i].second - points[j].second);

                if (dx + dy <= k) {
                    possible = true;
                    break;
                }
            }
            if (possible) {
                break;
            }
        }

        if (possible) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}