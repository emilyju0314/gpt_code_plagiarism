#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<pair<int, int>, int>> cells(n);
    for (int i = 0; i < n; i++) {
        cin >> cells[i].first.first >> cells[i].first.second >> cells[i].second;
    }
    
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<pair<int, int>> colors[4]; // Separate cells by color
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                colors[cells[i].second].push_back({cells[i].first.first, cells[i].first.second});
            }
        }
        bool possible = true;
        for (int i = 1; i <= 3; i++) {
            if (colors[i].size() != n/3) {
                possible = false;
                break;
            }
            sort(colors[i].begin(), colors[i].end());
        }
        if (possible) {
            bool valid = true;
            for (int i = 1; i <= 3; i++) {
                if (colors[i][0] != colors[i][n/3-1]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}