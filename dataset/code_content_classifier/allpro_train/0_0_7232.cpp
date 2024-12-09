#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> visited;
int n, m;

bool isValid(int x, int y, int height) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] <= height && visited[x][y] == 0;
}

bool isPossible(int height) {
    visited = vector<vector<int>>(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    int totalHay = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] > height) {
                totalHay += grid[i][j] - height;
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (isValid(x+1, y, height)) {
            visited[x+1][y] = 1;
            q.push({x+1, y});
        }
        if (isValid(x-1, y, height)) {
            visited[x-1][y] = 1;
            q.push({x-1, y});
        }
        if (isValid(x, y+1, height)) {
            visited[x][y+1] = 1;
            q.push({x, y+1});
        }
        if (isValid(x, y-1, height)) {
            visited[x][y-1] = 1;
            q.push({x, y-1});
        }
    }

    return totalHay == 0;
}

int main() {
    long long k;
    cin >> n >> m >> k;
    grid = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (ans != -1) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > ans) {
                    cout << ans << " ";
                } else {
                    cout << grid[i][j] << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}