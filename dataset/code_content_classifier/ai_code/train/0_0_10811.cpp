#include <iostream>
#include <vector>
using namespace std;

int H, W;
vector<vector<char>> orchard;
vector<vector<bool>> visited;

void explore(int x, int y, char fruit) {
    if (x < 0 || x >= H || y < 0 || y >= W || visited[x][y] || orchard[x][y] != fruit) {
        return;
    }

    visited[x][y] = true;
    explore(x - 1, y, fruit);
    explore(x + 1, y, fruit);
    explore(x, y - 1, fruit);
    explore(x, y + 1, fruit);
}

int countRelatives() {
    visited.assign(H, vector<bool>(W, false));
    int relativeCount = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                explore(i, j, orchard[i][j]);
                relativeCount++;
            }
        }
    }

    return relativeCount;
}

int main() {
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) {
            break;
        }

        orchard.assign(H, vector<char>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> orchard[i][j];
            }
        }

        int relatives = countRelatives();
        cout << relatives << endl;
    }

    return 0;
}