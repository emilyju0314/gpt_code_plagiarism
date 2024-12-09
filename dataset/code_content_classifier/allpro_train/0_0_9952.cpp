#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        result += grid[x - 1][y - 1];
    }

    cout << result << endl;

    return 0;
}