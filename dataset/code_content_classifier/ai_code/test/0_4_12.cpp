#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int nearest_pole_dist = n + m;
            for (int k = 0; k <= n; k++) {
                for (int l = 0; l <= m; l++) {
                    if (grid[k][l] == 1) {
                        int dist = (k - i) * (k - i) + (l - j) * (l - j);
                        nearest_pole_dist = min(nearest_pole_dist, dist);
                    }
                }
            }
            sum += nearest_pole_dist;
        }
    }

    cout << sum << endl;

    return 0;
}