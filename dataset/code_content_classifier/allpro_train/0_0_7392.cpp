#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Building {
    int height, left, right;
};

int main() {
    int n;
    cin >> n;

    vector<Building> buildings(n);

    for (int i = 0; i < n; i++) {
        cin >> buildings[i].height >> buildings[i].left >> buildings[i].right;
    }

    vector<pair<int, int>> corners;
    for (int i = 0; i < n; i++) {
        corners.emplace_back(buildings[i].left, buildings[i].height);
        corners.emplace_back(buildings[i].right, 0);
    }

    sort(corners.begin(), corners.end());

    vector<pair<int, int>> result;
    vector<int> heights(n, 0);
    int prev_height = 0;

    for (int i = 0; i < 2*n; i++) {
        int pos = corners[i].first;
        int current_height = 0;
        for (int j = 0; j < n; j++) {
            if (pos >= buildings[j].left && pos < buildings[j].right) {
                current_height = max(current_height, buildings[j].height);
            }
        }

        if (current_height != prev_height) {
            result.emplace_back(pos, current_height);
            prev_height = current_height;

            if (i == 2*n - 1) {
                result.emplace_back(pos, 0);
            }
        }
    }

    cout << result.size() << "\n";
    for (auto p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}