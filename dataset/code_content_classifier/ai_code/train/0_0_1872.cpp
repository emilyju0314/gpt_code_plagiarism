#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int minPaint = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                int maxX = i, maxY = j;
                int minX = i, minY = j;

                for (int k = i; k < n; k++) {
                    for (int l = j; l < m; l++) {
                        if (grid[k][l] == 'B') {
                            maxX = max(maxX, k);
                            maxY = max(maxY, l);
                            minX = min(minX, k);
                            minY = min(minY, l);
                        }
                    }
                }

                int sideLength = max(maxX - minX + 1, maxY - minY + 1);
                int blackCount = 0;

                for (int k = minX; k <= maxX; k++) {
                    for (int l = minY; l <= maxY; l++) {
                        if (grid[k][l] == 'W') {
                            blackCount++;
                        }
                    }
                }

                if (blackCount > 0) {
                    minPaint = min(minPaint, blackCount);
                }
            }
        }
    }

    if (minPaint == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minPaint << endl;
    }

    return 0;
}