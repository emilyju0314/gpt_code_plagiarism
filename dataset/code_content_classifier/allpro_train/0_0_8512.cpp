#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cubes(n);
    vector<vector<int>> colors(1e6 + 5);
    for (int i = 0; i < n; i++) {
        cin >> cubes[i].first >> cubes[i].second;
        colors[cubes[i].first].push_back(i);
    }

    long long max_height = 0;
    int max_color1, max_color2;
    for (int c1 = 1; c1 <= 1e6; c1++) {
        if (colors[c1].empty()) continue;
        
        for (int c2 = 1; c2 <= 1e6; c2++) {
            if (colors[c2].empty() || c1 == c2) continue;

            long long height = 0;
            vector<int> tower;
            int color_idx1 = 0, color_idx2 = 0;
            bool is_c1_turn = true;

            while (color_idx1 < colors[c1].size() || color_idx2 < colors[c2].size()) {
                if (is_c1_turn && color_idx1 < colors[c1].size()) {
                    height += cubes[colors[c1][color_idx1]].second;
                    tower.push_back(colors[c1][color_idx1]);
                    color_idx1++;
                    is_c1_turn = false;
                } else if (!is_c1_turn && color_idx2 < colors[c2].size()) {
                    height += cubes[colors[c2][color_idx2]].second;
                    tower.push_back(colors[c2][color_idx2]);
                    color_idx2++;
                    is_c1_turn = true;
                }
            }

            if (height > max_height) {
                max_height = height;
                max_color1 = c1;
                max_color2 = c2;
            }
        }
    }

    cout << max_height << endl;
    cout << max_height / 2 << endl;

    for (int idx : tower) {
        cout << idx + 1 << " ";
    }
    cout << endl;

    return 0;
}