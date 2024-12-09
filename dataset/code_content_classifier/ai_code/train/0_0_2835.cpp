#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, d;
    cin >> H >> W >> d;

    char colors[] = {'R', 'Y', 'G', 'B'};

    vector<vector<char>> grid(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int dist = i + j;
            grid[i][j] = colors[dist % d];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}