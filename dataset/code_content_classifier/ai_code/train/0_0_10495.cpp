#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        vector<string> directions(n);

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> directions[i];
        }

        int maxRobots = 0;
        int maxBlackCells = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (directions[i][j] == 'R' || directions[i][j] == 'D') {
                    maxBlackCells += grid[i][j] - '0';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (directions[i][m - 1] == 'R') {
                maxRobots++;
            }
        }

        for (int j = 0; j < m; j++) {
            if (directions[n - 1][j] == 'D') {
                maxRobots++;
            }
        }

        cout << maxRobots << " " << maxBlackCells << endl;
    }
    
    return 0;
}