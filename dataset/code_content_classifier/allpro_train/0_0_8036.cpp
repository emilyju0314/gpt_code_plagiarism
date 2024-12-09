#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    // Check if it is possible to only use right and down moves
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.' && ((i > 0 && grid[i - 1][j] == '.') || (j > 0 && grid[i][j - 1] == '.'))) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;

    return 0;
}