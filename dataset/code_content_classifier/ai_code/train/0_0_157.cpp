#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int w, h, n;
char house[16][16];
int dist[16][16][16][16][16];
int sx[3], sy[3], ex[3], ey[3];

struct State {
    int x[3], y[3], steps;

    State(int x1, int y1, int x2, int y2, int x3, int y3, int s) {
        x[0] = x1, x[1] = x2, x[2] = x3;
        y[0] = y1, y[1] = y2, y[2] = y3;
        steps = s;
    }
};

bool valid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && house[x][y] != '#';
}

int bfs() {
    queue<State> q;
    q.push(State(sx[0], sy[0], sx[1], sy[1], sx[2], sy[2], 0));
    
    memset(dist, -1, sizeof(dist));
    dist[sx[0]][sy[0]][sx[1]][sy[1]][sx[2]] = 0;
    
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        
        if (cur.x[0] == ex[0] && cur.y[0] == ey[0] && 
            cur.x[1] == ex[1] && cur.y[1] == ey[1] && 
            cur.x[2] == ex[2] && cur.y[2] == ey[2]) {
            return cur.steps;
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = cur.x[i] + dx[j];
                int ny = cur.y[i] + dy[j];
                
                if (valid(nx, ny)) {
                    int ns = dist[nx][ny][cur.x[(i+1)%3]][cur.y[(i+1)%3]][cur.x[(i+2)%3]];
                    if (ns == -1 || ns > cur.steps + 1) {
                        dist[nx][ny][cur.x[(i+1)%3]][cur.y[(i+1)%3]][cur.x[(i+2)%3]] = cur.steps + 1;
                        q.push(State(nx, ny, cur.x[(i+1)%3], cur.y[(i+1)%3], cur.x[(i+2)%3], cur.y[(i+2)%3], cur.steps + 1));
                    }
                }
            }
        }
    }
    
    return -1;
}

int main() {
    while (cin >> w >> h >> n) {
        if (w == 0 && h == 0 && n == 0) break;
        
        memset(sx, -1, sizeof(sx));
        memset(sy, -1, sizeof(sy));
        memset(ex, -1, sizeof(ex));
        memset(ey, -1, sizeof(ey));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> house[i][j];
                
                if (house[i][j] >= 'a' && house[i][j] <= 'z') {
                    sx[(int)(house[i][j] - 'a')] = i;
                    sy[(int)(house[i][j] - 'a')] = j;
                } else if (house[i][j] >= 'A' && house[i][j] <= 'Z') {
                    ex[(int)(house[i][j] - 'A')] = i;
                    ey[(int)(house[i][j] - 'A')] = j;
                }
            }
        }
        
        int ans = bfs();
        cout << ans << endl;
    }
    
    return 0;
}