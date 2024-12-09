#include <iostream>
#include <vector>

using namespace std;

bool canAchieveObjective(int H, int W, vector<vector<char>>& grid) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == '#') {
                bool adjacentBlack = false;
                if(i > 0 && grid[i-1][j] == '#') {
                    adjacentBlack = true;
                }
                if(j > 0 && grid[i][j-1] == '#') {
                    adjacentBlack = true;
                }
                if(!adjacentBlack) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    if(canAchieveObjective(H, W, grid)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}