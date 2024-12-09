#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int dx[] = {1, 0, -1, 0, 0, 0};
const int dy[] = {0, 1, 0, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

struct Point {
    int x, y, z;
    double dist;
};

bool isValid(int x, int y, int z) {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && z >= 0 && z < 3;
}

double shortestCable(const vector<vector<string>>& colony, int x1, int y1, int z1, int x2, int y2, int z2) {
    vector<vector<vector<bool>>> visited(3, vector<vector<bool>>(3, vector<bool>(3, false)));
    queue<Point> q;
    q.push({x1, y1, z1, 0.0});
    
    while(!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        if(cur.x == x2 && cur.y == y2 && cur.z == z2) {
            return cur.dist;
        }
        
        for(int i = 0; i < 6; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            double ndist = cur.dist + 1.0; // assuming unit distance for simplicity
            
            if(isValid(nx, ny, nz) && !visited[nx][ny][nz] && colony[nx][ny][nz] == '#') {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, ndist});
            }
        }
    }
    
    return -1; // No path found
}

int main() {
    int x1, y1, z1, x2, y2, z2;
    
    while(true) {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        
        if(x1 == 0 && y1 == 0 && z1 == 0 && x2 == 0 && y2 == 0 && z2 == 0) {
            break;
        }
        
        vector<vector<string>> colony(3, vector<string>(3));
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> colony[i][j];
            }
        }
        
        double length = shortestCable(colony, x1, y1, z1, x2, y2, z2);
        cout << fixed << length << endl;
    }
    
    return 0;
}