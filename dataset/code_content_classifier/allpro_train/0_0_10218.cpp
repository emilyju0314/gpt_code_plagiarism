#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int H, W, R, C;
    
    while (cin >> H >> W >> R >> C) {
        if (H == 0 && W == 0 && R == 0 && C == 0) break;
        
        int Horz[501][501];
        int Vert[501][501];
        
        for (int i = 1; i <= H + 1; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> Horz[i][j];
            }
        }
        
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W + 1; j++) {
                cin >> Vert[i][j];
            }
        }
        
        bool visited[501][501];
        memset(visited, false, sizeof(visited));
        
        queue<pair<int, int>> q;
        q.push({R, C});
        
        bool escaped = false;
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if (r == 1) {
                escaped = true;
                break;
            }
            
            if (visited[r][c]) continue;
            visited[r][c] = true;
            
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < 1 || nr > H || nc < 1 || nc > W) continue;
                if (visited[nr][nc]) continue;
                
                if (i == 0 && Horz[r][c] == 1) continue;
                if (i == 1 && Horz[nr][c] == 1) continue;
                if (i == 2 && Vert[r][c] == 1) continue;
                if (i == 3 && Vert[r][nc] == 1) continue;
                
                q.push({nr, nc});
            }
        }
        
        cout << (escaped ? "Yes" : "No") << endl;
    }
    
    return 0;
}