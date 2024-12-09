#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> operations;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < H - 1 && grid[i][j] % 2 != 0) {
                grid[i][j]--;
                grid[i + 1][j]++;
                operations.push_back({i + 1, j + 1, i + 2, j + 1});
            }
            if (j < W - 1 && grid[i][j] % 2 != 0) {
                grid[i][j]--;
                grid[i][j + 1]++;
                operations.push_back({i + 1, j + 1, i + 1, j + 2});
            }
        }
    }

    cout << operations.size() << endl;
    for (auto op : operations) {
        for (auto val : op) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}