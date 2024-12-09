#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<vector<char>> field;

bool isClear(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W) {
        return false;
    }
    if (field[x][y] == '.' || field[x][y] == '@') {
        return true;
    }
    return false;
}

bool canMove(int x, int y, int dx, int dy) {
    if (!isClear(x, y) || !isClear(x + dx, y + dy) || field[x + dx][y + dy] == 'o') {
        return false;
    }
    return true;
}

bool solve() {
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (field[x][y] == '@') {
                if (canMove(x, y, -1, 0) || canMove(x, y, 1, 0) ||
                    canMove(x, y, 0, -1) || canMove(x, y, 0, 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W;
    field.resize(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> field[i][j];
        }
    }

    if (solve()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}