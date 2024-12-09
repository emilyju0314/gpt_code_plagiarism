#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    set<pair<int, int>> obstacles;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        obstacles.insert({x, y});
    }

    bool possible = true;
    int direction = 1; // Initial direction
    int x = 1, y = 1;

    vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
    visited[1][1] = 1;

    for (int i = 0; i < n * m - k; i++) {
        if (direction == 1) {
            if (y < m && obstacles.count({x, y+1}) == 0) {
                y++;
            } else {
                direction = 2;
            }
        } else if (direction == 2) {
            if (x < n && obstacles.count({x+1, y}) == 0) {
                x++;
            } else {
                direction = 3;
            }
        } else if (direction == 3) {
            if (y > 1 && obstacles.count({x, y-1}) == 0) {
                y--;
            } else {
                direction = 4;
            }
        } else {
            if (x > 1 && obstacles.count({x-1, y}) == 0) {
                x--;
            } else {
                direction = 1;
            }
        }

        if (visited[x][y] == 1) {
            possible = false;
            break;
        } else {
            visited[x][y] = 1;
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}