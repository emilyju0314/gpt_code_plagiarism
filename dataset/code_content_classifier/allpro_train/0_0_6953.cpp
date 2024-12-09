#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
};

int n, m;
char grid[15][15];
int visited[15][15][15][15];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

int bfs(Point start, Point end) {
    queue<pair<Point, int>> q;
    q.push({start, 0});
    
    while (!q.empty()) {
        Point curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (curr.x == end.x && curr.y == end.y) {
            return dist;
        }
        
        for (int i = 0; i < 4; i++) {
            int x = curr.x + dx[i];
            int y = curr.y + dy[i];
            if (isValid(x, y) && !visited[x][y][curr.x][curr.y]) {
                q.push({{x, y}, dist+1});
                visited[x][y][curr.x][curr.y] = 1;
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> n >> m;
    Point start, end;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '1') {
                start.x = i;
                start.y = j;
            }
            if (grid[i][j] == '@') {
                end.x = i;
                end.y = j;
            }
        }
    }
    
    int result = bfs(start, end);
    cout << result << endl;
    
    return 0;
}