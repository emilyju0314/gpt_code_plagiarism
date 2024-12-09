#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> colors[3]; // To store the coordinates of cells of each color

    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        colors[c-1].push_back({x, y});
    }

    map<int, int> colorIds = {{0, 0}, {1, 1}, {2, 2}}; // Assigning each color an ID

    for (int i = 0; i < 3; i++) {
        sort(colors[i].begin(), colors[i].end());
    }

    // Finding the common x-coordinate for each color
    int xVals[3];
    for (int i = 0; i < 3; i++) {
        xVals[i] = colors[i][n/3].first;
    }

    // Finding the common y-coordinate for each color
    int yVals[3];
    for (int i = 0; i < 3; i++) {
        map<int, int> yCounts;
        for (auto p : colors[i]) {
            yCounts[p.second]++;
        }
        for (auto p : yCounts) {
            if (p.second == n/3) {
                yVals[i] = p.first;
                break;
            }
        }
    }

    int k = 0;
    int commonCount = 3*n/3; // Count of cells in the common area for all colors
    for (int i = 0; i < 3; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                count += count_if(colors[j].begin(), colors[j].end(), [=](pair<int, int> p) {
                    return ((p.first == xVals[i] || p.second == yVals[i]) && colorIds[j] == j);
                });
            }
        }
        k = max(k, commonCount - count);
    }

    cout << k << endl;

    return 0;
}