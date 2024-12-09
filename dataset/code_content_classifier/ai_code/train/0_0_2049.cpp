#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int n, m;
vector<string> matrix;
vector<vector<bool>> visited;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    
    for(int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(isValid(newX, newY) && !visited[newX][newY] && matrix[newX][newY] == '1') {
            dfs(newX, newY);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        string row;
        cin >> row;
        matrix.push_back(row);
    }
    
    visited.resize(n, vector<bool>(m, false));
    
    int components = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && matrix[i][j] == '1') {
                dfs(i, j);
                components++;
            }
        }
    }
    
    cout << components << endl;
    
    return 0;
}