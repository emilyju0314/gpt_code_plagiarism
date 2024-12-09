#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> geoPanels;
vector<vector<int>> geoSymbols;
int n, m, x, y;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void repaintPanels(int color, int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if (cx < 0 || cx >= n || cy < 0 || cy >= m || geoPanels[cx][cy] == 0) {
            continue;
        }
        
        if (geoPanels[cx][cy] == color) {
            geoPanels[cx][cy] = 0;
            
            for (int i = 0; i < 4; i++) {
                q.push({cx + dx[i], cy + dy[i]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    geoPanels.resize(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> geoPanels[i][j];
        }
    }
    
    geoSymbols.resize(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> geoSymbols[i][j];
        }
    }
    
    cin >> x >> y;
    x--; y--;
    
    int repaintings = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if (geoSymbols[cx][cy] == -1) {
            continue;
        }
        
        repaintPanels(geoSymbols[cx][cy], cx, cy);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (geoPanels[i][j] == 0 && geoSymbols[i][j] != -1 && geoSymbols[i][j] != geoPanels[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        repaintings++;
    }
    
    cout << repaintings << endl;
    
    return 0;
}