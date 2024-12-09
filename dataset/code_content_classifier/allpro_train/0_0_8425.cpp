#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m; j++) {
                grid[i][j] = row[j] - '0';
            }
        }

        vector<tuple<int, int, int>> operations;

        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m-1; j++) {
                if (grid[i][j] == 1) {
                    operations.push_back({i+1, j+1, i+1, j+2, i+2, j+1});
                    grid[i][j] = !grid[i][j];
                    grid[i][j+1] = !grid[i][j+1];
                    grid[i+1][j] = !grid[i+1][j];
                }
            }
        }

        cout << operations.size() << endl;
        for (auto [x1, y1, x2, y2, x3, y3] : operations) {
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
        }
    }

    return 0;
}