#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, L;
    while (true) {
        cin >> H >> W >> L;
        if (H == 0 && W == 0 && L == 0) {
            break;
        }

        vector<vector<char>> maze(H, vector<char>(W));
        int start_row, start_col;
        char start_dir;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'N' || maze[i][j] == 'E' || maze[i][j] == 'S' || maze[i][j] == 'W') {
                    start_row = i;
                    start_col = j;
                    start_dir = maze[i][j];
                }
            }
        }

        int row = start_row;
        int col = start_col;
        char dir = start_dir;
        long long steps = 0;

        while (steps < L) {
            if (dir == 'N' && row-1 >= 0 && maze[row-1][col] != '#') {
                row--;
                steps++;
            } else if (dir == 'E' && col+1 < W && maze[row][col+1] != '#') {
                col++;
                steps++;
            } else if (dir == 'S' && row+1 < H && maze[row+1][col] != '#') {
                row++;
                steps++;
            } else if (dir == 'W' && col-1 >= 0 && maze[row][col-1] != '#') {
                col--;
                steps++;
            } else {
                dir = (dir == 'N') ? 'E' : (dir == 'E') ? 'S' : (dir == 'S') ? 'W' : 'N';
            }
        }

        cout << row+1 << " " << col+1 << " " << dir << endl;
    }

    return 0;
}