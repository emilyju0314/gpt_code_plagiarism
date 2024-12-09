#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector<pair<int, int>> invert;
        if (grid[0][1] == grid[1][0]) {
            if (grid[n-1][n-2] == grid[n-2][n-1] && grid[0][1] != grid[n-1][n-2]) {
                invert.push_back({1, 2});
            } else if (grid[0][1] != grid[n-1][n-2]) {
                invert.push_back({1, 2});
                invert.push_back({n, n-1});
            }
        } else {
            if (grid[n-1][n-2] == grid[n-2][n-1] && grid[0][1] != grid[n-1][n-2]) {
                invert.push_back({2, 1});
            } else {
                invert.push_back({2, 1});
                invert.push_back({n-1, n});
            }
        }

        cout << invert.size() << endl;
        for (auto p : invert) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}