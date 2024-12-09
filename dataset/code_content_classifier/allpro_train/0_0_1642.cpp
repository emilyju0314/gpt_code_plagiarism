#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int N, W, H;
    cin >> N >> W >> H;

    vector<vector<int>> grid(H, vector<int>(W, -1));
    vector<pair<int, int>> slimes(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        slimes[i] = {x, y};
        grid[y][x] = i;
    }

    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    auto unite = [&](int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    };

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (grid[y][x] == -1) {
                continue;
            }

            if (x < W - 1 && grid[y][x + 1] != -1) {
                unite(grid[y][x], grid[y][x + 1]);
            }
            if (y < H - 1 && grid[y + 1][x] != -1) {
                unite(grid[y][x], grid[y + 1][x]);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (find(i) == i) {
            result++;
        }
    }

    cout << result - 1 << endl;

    return 0;
}