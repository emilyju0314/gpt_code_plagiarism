#include <iostream>
#include <vector>

void dfs(int x, int y, int w, int h, std::vector<std::vector<int>>& map) {
    if (x < 0 || x >= w || y < 0 || y >= h || map[y][x] == 0) {
        return;
    }
    
    map[y][x] = 0;
    
    dfs(x-1, y, w, h, map);
    dfs(x+1, y, w, h, map);
    dfs(x, y-1, w, h, map);
    dfs(x, y+1, w, h, map);
    dfs(x-1, y-1, w, h, map);
    dfs(x+1, y-1, w, h, map);
    dfs(x-1, y+1, w, h, map);
    dfs(x+1, y+1, w, h, map);
}

int countIslands(int w, int h, std::vector<std::vector<int>>& map) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 1) {
                count++;
                dfs(j, i, w, h, map);
            }
        }
    }
    return count;
}

int main() {
    int w, h;
    while (std::cin >> w >> h) {
        if (w == 0 && h == 0) {
            break;
        }
        
        std::vector<std::vector<int>> map(h, std::vector<int>(w));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                std::cin >> map[i][j];
            }
        }
        
        int islands = countIslands(w, h, map);
        std::cout << islands << std::endl;
    }
    
    return 0;
}