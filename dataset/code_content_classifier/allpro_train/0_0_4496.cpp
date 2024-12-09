#include <iostream>
#include <vector>
#include <string>

using namespace std;

int H, W;
vector<string> pond;
string movements;

bool solve(int x, int y, string currMovements) {
    if (pond[x][y] == '.') {
        return false;
    } else if (pond[x][y] == 'o' && pond[x][y + 1] == '.') {
        return true;
    } else if (x > 0 && solve(x - 1, y, currMovements + "U")) {
        movements = currMovements + "U";
        return true;
    } else if (x < H - 1 && solve(x + 1, y, currMovements + "D")) {
        movements = currMovements + "D";
        return true;
    } else if (y > 0 && solve(x, y - 1, currMovements + "L")) {
        movements = currMovements + "L";
        return true;
    } else if (y < W - 1 && solve(x, y + 1, currMovements + "R")) {
        movements = currMovements + "R";
        return true;
    }

    return false;
}

int main() {
    cin >> H >> W;

    pond.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> pond[i];
    }

    int frogX, frogY;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (pond[i][j] == 'U' || pond[i][j] == 'D' || pond[i][j] == 'L' || pond[i][j] == 'R') {
                frogX = i;
                frogY = j;
            }
        }
    }

    if (solve(frogX, frogY, "")) {
        cout << movements << endl;
    }

    return 0;
}