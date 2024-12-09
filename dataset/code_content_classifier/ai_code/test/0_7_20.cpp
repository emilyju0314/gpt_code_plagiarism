#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }

        int operations = 0;

        for (int i = 0; i < n - 4; i++) {
            for (int j = 0; j < m - 3; j++) {
                int curr = 0;

                for (int x = i; x < i + 5; x++) {
                    for (int y = j; y < j + 4; y++) {
                        if (x == i || x == i + 4 || y == j || y == j + 3) {
                            curr += grid[x][y];
                        } else {
                            curr += 1 - grid[x][y];
                        }
                    }
                }

                operations = max(operations, min(curr, 20 - curr));
            }
        }

        cout << operations << endl;
    }

    return 0;
}