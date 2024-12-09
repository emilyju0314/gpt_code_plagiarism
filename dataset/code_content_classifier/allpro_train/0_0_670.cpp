#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    vector<string> adj_grid(H, string(W, '0'));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                adj_grid[i][j] = '#';
                continue;
            }

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int ni = i + dx;
                    int nj = j + dy;
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                        continue;
                    }
                    if (grid[ni][nj] == '#') {
                        adj_grid[i][j]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        cout << adj_grid[i] << endl;
    }

    return 0;
}