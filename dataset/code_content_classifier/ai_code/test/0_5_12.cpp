#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(m+1));
    vector<vector<int>> dist(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (grid[i][j] == 1) continue;
            dist[i][j] = n + m + 1;

            for (int x = 0; x <= n; x++) {
                for (int y = 0; y <= m; y++) {
                    if (grid[x][y] == 1) {
                        int d = (i-x)*(i-x) + (j-y)*(j-y);
                        dist[i][j] = min(dist[i][j], d);
                    }
                }
            }
        }
    }

    int total_sum = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            total_sum += dist[i][j];
        }
    }

    cout << total_sum << endl;

    return 0;
}