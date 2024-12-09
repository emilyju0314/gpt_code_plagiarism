#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> cells; // (color, (x, y))
    vector<int> count(4, 0); // count of cells for each color

    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        cells.push_back({c, {x, y}});
        count[c]++;
    }

    sort(cells.begin(), cells.end());

    int maxK = 0;
    for (int k = 0; k <= n/3; k++) {
        int k1 = k, k2 = n/3 - k, k3 = n/3 - k;

        vector<int> minX(4, INT_MAX), maxX(4, INT_MIN), minY(4, INT_MAX), maxY(4, INT_MIN);
        
        for (auto cell : cells) {
            int c = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            if (k1 > 0 && c == 1) {
                minX[c] = min(minX[c], x);
                maxX[c] = max(maxX[c], x);
                minY[c] = min(minY[c], y);
                maxY[c] = max(maxY[c], y);
                k1--;
            } else if (k2 > 0 && c == 2) {
                minX[c] = min(minX[c], x);
                maxX[c] = max(maxX[c], x);
                minY[c] = min(minY[c], y);
                maxY[c] = max(maxY[c], y);
                k2--;
            } else if (k3 > 0 && c == 3) {
                minX[c] = min(minX[c], x);
                maxX[c] = max(maxX[c], x);
                minY[c] = min(minY[c], y);
                maxY[c] = max(maxY[c], y);
                k3--;
            }
        }

        bool valid = true;
        for (int i = 1; i <= 3; i++) {
            if (count[i] > 0 && (minX[i] == INT_MAX || maxX[i] == INT_MIN || minY[i] == INT_MAX || maxY[i] == INT_MIN)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            maxK = max(maxK, 3*k);
        }
    }

    cout << maxK << endl;

    return 0;
}