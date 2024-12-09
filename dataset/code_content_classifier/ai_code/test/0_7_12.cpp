#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(m+1));

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
            int min_distance = n + m;
            for (int k = 0; k <= n; k++) {
                for (int l = 0; l <= m; l++) {
                    if (grid[k][l] == 1) {
                        int distance = (k - i) * (k - i) + (l - j) * (l - j);
                        min_distance = min(min_distance, distance);
                    }
                }
            }
            sum += min_distance;
        }
    }

    cout << sum << endl;

    return 0;
}