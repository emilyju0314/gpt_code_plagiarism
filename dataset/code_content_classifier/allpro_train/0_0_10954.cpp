
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    int grid[20][20][10000]; // 3D array to store number of ways to reach each cell at each time moment
    memset(grid, 0, sizeof(grid));

    grid[0][0][1] = 1;

    for (int i = 0; i < q; i++) {
        int tp, x, y, t;
        cin >> tp >> x >> y >> t;

        if (tp == 2) {
            grid[x-1][y-1][t] = 0;
        } else if (tp == 3) {
            grid[x-1][y-1][t] = grid[x-1][y-1][t-1];  
        } else {
            grid[x-1][y-1][t] = 0;
            grid[x-1][y-1][t] = (grid[x-1][y-1][t] + grid[max(0, x-2)][y-1][t-1])%MOD;
            grid[x-1][y-1][t] = (grid[x-1][y-1][t] + grid[x%20][y-2][t-1])%MOD;
            grid[x-1][y-1][t] = (grid[x-1][y-1][t] + grid[x][y%20][t-1])%MOD;
            grid[x-1][y-1][t] = (grid[x-1][y-1][t] + grid[x][min(n-1, y)][t-1])%MOD;
        }

        cout << grid[x-1][y-1][t] << endl;
    }

    return 0;
}