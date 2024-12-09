#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<char>> map;
vector<vector<int>> dist;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    
    dist[x][y] = 0;
    
    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            
            if (isValid(newX, newY) && map[newX][newY] != '#' && dist[newX][newY] > dist[currX][currY] + (map[newX][newY] == '.' ? 1 : 0)) {
                dist[newX][newY] = dist[currX][currY] + (map[newX][newY] == '.' ? 1 : 0);
                q.push({newX, newY});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    map.resize(n, vector<char>(m));
    dist.resize(n, vector<int>(m, INF));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] >= '1' && map[i][j] <= '3') {
                bfs(i, j);
            }
        }
    }
    
    int minCells = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.') {
                minCells = min(minCells, dist[i][j]);
            }
        }
    }
    
    if (minCells == INF) {
        cout << -1 << endl;
    } else {
        cout << minCells << endl;
    }
    
    return 0;
}