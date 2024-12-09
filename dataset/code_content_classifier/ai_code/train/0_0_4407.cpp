#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<vector<char>> chocolate;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || visited[x][y] || chocolate[x][y] == '.') {
        return;
    }
    
    visited[x][y] = true;
    
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int countChocolatePieces() {
    visited.assign(h, vector<bool>(w, false));
    int count = 0;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j] && chocolate[i][j] == '#') {
                count++;
                dfs(i, j);
            }
        }
    }
    
    return count;
}

int main() {
    while (true) {
        cin >> h >> w;
        
        if (h == 0 && w == 0) {
            break;
        }
        
        chocolate.resize(h, vector<char>(w));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> chocolate[i][j];
            }
        }
        
        cout << countChocolatePieces() << endl;
        
        chocolate.clear();
    }
    
    return 0;
}