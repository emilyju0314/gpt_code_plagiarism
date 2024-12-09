#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 10;
const int MAX_M = 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int m, n;
int town[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int num_houses;
int num_directions;

void distributeGifts(int x, int y, int houses_visited, int directions_taken) {
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || town[x][y] == 0) {
        return;
    }

    visited[x][y] = true;
    if (town[x][y] == 1) {
        houses_visited++;
    }

    if (houses_visited == num_houses) {
        if (town[x][y] == 2) {
            num_directions++;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            if (i + directions_taken == 3) {
                continue; // Skip going back the same way
            }
            distributeGifts(x + dx[i], y + dy[i], houses_visited, i);
        }
    }

    visited[x][y] = false;
    if (town[x][y] == 1) {
        houses_visited--;
    }
}

int main() {
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }

        num_houses = 0;
        num_directions = 0;
        int church_x, church_y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> town[i][j];
                if (town[i][j] == 1) {
                    num_houses++;
                } else if (town[i][j] == 2) {
                    church_x = i;
                    church_y = j;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        distributeGifts(church_x, church_y, 0, -1); // Start from the church with 0 houses and no previous direction taken

        cout << num_directions << endl;
    }

    return 0;
}