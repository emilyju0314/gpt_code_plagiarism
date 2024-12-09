#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    int totalDistance = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int minDistance = INT_MAX;
            for (int x = 0; x <= n; x++) {
                for (int y = 0; y <= m; y++) {
                    if (grid[x][y] == 1) {
                        int distance = (x-i)*(x-i) + (y-j)*(y-j);
                        minDistance = min(minDistance, distance);
                    }
                }
            }
            totalDistance += minDistance;
        }
    }

    cout << totalDistance << endl;

    return 0;
}