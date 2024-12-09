#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));

    // Input grid values
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    int sum = 0;

    // Calculate the sum of squared Euclidean distances for all points
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int min_dist = INT_MAX;
            for(int x = 0; x <= n; x++) {
                for(int y = 0; y <= m; y++) {
                    if(grid[x][y] == 1) {
                        int dist = pow(x - i, 2) + pow(y - j, 2);
                        min_dist = min(min_dist, dist);
                    }
                }
            }
            sum += min_dist;
        }
    }

    cout << sum << endl;

    return 0;
}