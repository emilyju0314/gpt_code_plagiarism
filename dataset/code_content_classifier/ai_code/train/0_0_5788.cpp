#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Point {
    int x, y;
};

int bfs(vector<vector<int>>& maze, Point start, Point end, int N) {
    int H = maze.size();
    int W = maze[0].size();
    
    vector<vector<int>> dist(H, vector<int>(W, INF));
    dist[start.y][start.x] = 0;
    
    queue<Point> q;
    q.push(start);
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        if (current.x == end.x && current.y == end.y) {
            return dist[current.y][current.x];
        }
        
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= N; j++) {
                int nx = current.x + dx[i] * j;
                int ny = current.y + dy[i] * j;
                
                if (nx < 0 || ny < 0 || nx >= W || ny >= H || maze[ny][nx] == 1) {
                    break;
                }
                
                if (dist[ny][nx] > dist[current.y][current.x] + 1) {
                    dist[ny][nx] = dist[current.y][current.x] + 1;
                    q.push({nx, ny});
                }
                
                if (nx == end.x && ny == end.y) {
                    return dist[ny][nx];
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int W, H;
    
    while (cin >> W >> H) {
        if (W == 0 && H == 0) {
            break;
        }
        
        vector<vector<int>> maze(H*2-1, vector<int>(W*2-1));
        
        for (int i = 0; i < H*2-1; i++) {
            for (int j = 0; j < W*2-1; j++) {
                cin >> maze[i][j];
            }
        }
        
        int xs, ys, xm, ym, xk, yk, xd, yd, N;
        cin >> xs >> ys >> xm >> ym >> xk >> yk >> xd >> yd >> N;
        
        Point start = {xs*2, ys*2};
        Point end = {xd*2, yd*2};
        
        int result = bfs(maze, start, end, N);
        
        cout << result << endl;
    }
    
    return 0;
}