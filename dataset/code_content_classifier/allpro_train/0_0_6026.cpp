#include <iostream>
#include <vector>

using namespace std;

bool checkWinningMove(vector<string>& grid, int x, int y) {
    int dx[] = {1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1};

    for(int i = 0; i < 4; i++) {
        int count = 1;
        int cx = x, cy = y;

        while(cx + dx[i] >= 0 && cx + dx[i] < 10 && cy + dy[i] >= 0 && cy + dy[i] < 10 && grid[cx + dx[i]][cy + dy[i]] == 'X') {
            count++;
            cx += dx[i];
            cy += dy[i];
        }

        cx = x, cy = y;

        while(cx - dx[i] >= 0 && cx - dx[i] < 10 && cy - dy[i] >= 0 && cy - dy[i] < 10 && grid[cx - dx[i]][cy - dy[i]] == 'X') {
            count++;
            cx -= dx[i];
            cy -= dy[i];
        }

        if(count >= 5) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<string> grid(10);
    for(int i = 0; i < 10; i++) {
        cin >> grid[i];
    }

    bool possible = false;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(grid[i][j] == '.') {
                grid[i][j] = 'X';
                if(checkWinningMove(grid, i, j)) {
                    possible = true;
                }
                grid[i][j] = '.';
            }
        }
    }

    if(possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}