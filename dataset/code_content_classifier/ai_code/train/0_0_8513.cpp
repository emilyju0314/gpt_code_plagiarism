#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> image;
vector<vector<bool>> visited;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny) && image[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    image.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    int circles = 0;
    int squares = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (image[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                int blackCount = 0;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if (visited[ii][jj]) {
                            blackCount++;
                            visited[ii][jj] = false;
                        }
                    }
                }
                if (blackCount >= 15) {
                    if (blackCount >= 2 * 3.1415926535 * blackCount / 4) {
                        circles++;
                    } else {
                        squares++;
                    }
                }
            }
        }
    }

    cout << circles << " " << squares << endl;

    return 0;
}