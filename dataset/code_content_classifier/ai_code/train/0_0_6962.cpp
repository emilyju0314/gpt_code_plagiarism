#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<vector<int>> grid;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int n, k;

bool inBounds(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    cin >> n >> k;
    grid.resize(n, vector<int>(n, -1));

    for (int i = 0; i < k; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--, y--;

        if (c == 'o') grid[x][y] = 1;
        else grid[x][y] = 0;
    }

    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == -1) {
                int cur = 0;

                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (inBounds(nx, ny) && grid[nx][ny] == 1) {
                        cur++;
                    }
                }

                ans = (ans * cur) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}