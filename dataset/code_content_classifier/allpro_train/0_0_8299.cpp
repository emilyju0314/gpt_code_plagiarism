#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C, N;
    cin >> R >> C >> N;

    vector<vector<int>> grid(R + 1, vector<int>(C + 1, -1));

    for (int i = 0; i < N; i++) {
        int r, c, a;
        cin >> r >> c >> a;
        grid[r][c] = a;
    }

    bool possible = true;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == -1) {
                grid[r][c] = 0;
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] + grid[r+1][c+1] != grid[r][c+1] + grid[r+1][c]) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}