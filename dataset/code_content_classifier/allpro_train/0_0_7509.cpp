#include <iostream>
#include <vector>
#include <algorithm>

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

    int complexity = 0;
    bool hasBlack = false;
    bool hasWhite = false;

    for (int i = 0; i < H; i++) {
        if (find(grid[i].begin(), grid[i].end(), '#') != grid[i].end()) {
            hasBlack = true;
        } else {
            hasWhite = true;
        }
    }

    if (hasBlack && hasWhite) {
        complexity = 1;
    } else {
        complexity = 0;
    }

    cout << complexity << endl;

    return 0;
}