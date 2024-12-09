#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        if (grid[x-1][y-1] == 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}