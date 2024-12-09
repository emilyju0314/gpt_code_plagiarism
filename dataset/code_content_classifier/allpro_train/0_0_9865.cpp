#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<vector<int>> chocolate;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= H || y >= W || chocolate[x][y] == 0) {
        return 0;
    }
    
    int eaten = 1;
    chocolate[x][y] = 0;
    
    for (int i = 0; i < 4; i++) {
        eaten += dfs(x + dx[i], y + dy[i]);
    }
    
    return eaten;
}

int main() {
    
    while (true) {
        cin >> H >> W;
        
        if (H == 0 && W == 0) {
            break;
        }
        
        chocolate.clear();
        chocolate.resize(H, vector<int>(W));
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> chocolate[i][j];
            }
        }
        
        int maxEaten = 0;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (chocolate[i][j] == 1) {
                    maxEaten = max(maxEaten, dfs(i, j));
                }
            }
        }
        
        cout << maxEaten << endl;
    }
    
    return 0;
}