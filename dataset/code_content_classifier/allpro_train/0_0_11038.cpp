#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

struct Scayger {
    int x, y, time;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, males, females;
vector<string> grid;
vector<vector<vector<int>>> dist;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = vector<int>(n, vector<int>(m, INF));
    dist[sx][sy][sx][sy] = 0;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            
            if (isValid(nx, ny) && dist[sx][sy][nx][ny] == INF) {
                dist[sx][sy][nx][ny] = dist[sx][sy][curr.first][curr.second] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool isPossible(int totalTime) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (grid[k][l] == '#' || (k == i && l == j)) continue;
                    
                    int timeNeeded = dist[i][j][k][l];
                    if (timeNeeded <= totalTime && (timeNeeded % 2 == totalTime % 2)) {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m >> males >> females;
    
    grid.resize(n);
    dist.resize(n, vector<vector<int>>(m));
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(i, j);
        }
    }
    
    int r, c, t;
    cin >> r >> c >> t;
    
    for (int i = 0; i < males; i++) {
        Scayger male;
        cin >> male.x >> male.y >> male.time;
        grid[male.x - 1][male.y - 1] = 'M';
    }
    
    for (int i = 0; i < females; i++) {
        Scayger female;
        cin >> female.x >> female.y >> female.time;
        grid[female.x - 1][female.y - 1] = 'F';
    }
    
    int totalTime = max(t, (n + m) * (males + females) + 1);
    int left = -1, right = totalTime;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isPossible(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}