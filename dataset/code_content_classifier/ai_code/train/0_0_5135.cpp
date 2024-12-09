#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        grid[x][y] = i;

        if(i >= 9) {
            bool found = false;
            for(int j = 0; j < n - 2; j++) {
                for(int k = 0; k < n - 2; k++) {
                    if(grid[j][k] != 0 && grid[j][k+1] == i-1 && grid[j][k+2] == i-2 &&
                       grid[j+1][k] == i-3 && grid[j+1][k+1] == i-4 && grid[j+1][k+2] == i-5 &&
                       grid[j+2][k] == i-6 && grid[j+2][k+1] == i-7 && grid[j+2][k+2] == i-8) {
                        cout << i << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}