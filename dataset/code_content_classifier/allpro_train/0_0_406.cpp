#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    unordered_map<int, int> countByDistance;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    int totalTriples = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                for (int r = 0; r < H; r++) {
                    for (int c = 0; c < W; c++) {
                        if (grid[r][c] == '#') {
                            int distance = abs(i - r) + abs(j - c);
                            totalTriples += countByDistance[distance];
                            countByDistance[distance]++;
                        }
                    }
                }
            }
        }
    }

    cout << totalTriples << endl;

    return 0;
}