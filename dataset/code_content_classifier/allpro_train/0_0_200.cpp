#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<char>> maze;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] != '.') {
        return;
    }
    
    maze[i][j] = 'X';
    k--;
    
    if (k == 0) {
        return;
    }
    
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    cin >> n >> m >> k;
    
    maze.resize(n, vector<char>(m));
    
    int s = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                s++;
            }
        }
    }
    
    k = s - k;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                dfs(i, j);
                break;
            }
        }
        
        if (k == 0) {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    
    return 0;
}