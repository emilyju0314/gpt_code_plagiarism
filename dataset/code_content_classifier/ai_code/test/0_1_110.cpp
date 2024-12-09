#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> colors[4];
    unordered_map<int, vector<pair<int, int>>> cells;

    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        colors[c].push_back(i);
        cells[i] = {x, y};
    }

    int ans = 0;

    for (int i = 0; i < 1 << 3; i++) {
        vector<int> comb;
        for (int j = 0; j < 3; j++) {
            if (i & 1 << j) {
                comb.insert(comb.end(), colors[j + 1].begin(), colors[j + 1].end());
            }
        }

        if (comb.size() % 3 != 0) continue;

        sort(comb.begin(), comb.end());

        vector<int> taken;
        do {
            vector<pair<int, int>> corners[3];

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < comb.size() / 3; k++) {
                    corners[j].push_back(cells[comb[j * comb.size() / 3 + k]]);
                }
            }

            int min_x = min({corners[0][0].first, corners[1][0].first, corners[2][0].first});
            int min_y = min({corners[0][0].second, corners[1][0].second, corners[2][0].second});
            int max_x = max({corners[0][0].first, corners[1][0].first, corners[2][0].first});
            int max_y = max({corners[0][0].second, corners[1][0].second, corners[2][0].second});

            bool valid = true;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < comb.size() / 3; k++) {
                    int x = corners[j][k].first;
                    int y = corners[j][k].second;
                    if (x < min_x || x > max_x || y < min_y || y > max_y) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) {
                ans = max(ans, (int)comb.size());
            }
        } while (next_permutation(comb.begin(), comb.end()));
    }

    cout << ans << endl;

    return 0;
}