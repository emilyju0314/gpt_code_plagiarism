#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, q;
vector<vector<int>> flag;
vector<vector<int>> components;
vector<vector<bool>> visited;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y, int component_num) {
    visited[x][y] = true;
    components[x][y] = component_num;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && flag[nx][ny] == flag[x][y] && !visited[nx][ny]) {
            dfs(nx, ny, component_num);
        }
    }
}

int main() {
    cin >> n >> m >> q;
    
    flag.resize(n, vector<int>(m));
    components.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> flag[i][j];
        }
    }
    
    int component_num = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j, component_num++);
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int beauty = 0;
        for (int j = 0; j < n; j++) {
            vector<int> components_count(component_num, 0);
            for (int k = l - 1; k < r; k++) {
                components_count[components[j][k]]++;
            }
            
            for (int component_count : components_count) {
                if (component_count > 0) {
                    beauty++;
                }
            }
        }
        cout << beauty << endl;
    }
    
    return 0;
}