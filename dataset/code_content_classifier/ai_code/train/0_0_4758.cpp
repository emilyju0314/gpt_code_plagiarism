#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool check_cover_forest(vector<vector<int>>& forest, int H, int W, int x, int y) {
    vector<vector<int>> visited(H, vector<int>(W, 0));
    
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 4; i++) {
            int posX = x + dx[i];
            int posY = y + dy[i];
            
            while (posX >= 0 && posX < H && posY >= 0 && posY < W) {
                visited[posX][posY] = 1;
                if (forest[posX][posY] == 1) {
                    forest[posX][posY] = 0;
                } else {
                    forest[posX][posY] = 1;
                }
                posX += dx[i];
                posY += dy[i];
            }
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (forest[i][j] == 1) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<vector<int>> forest(H, vector<int>(W));
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> forest[i][j];
        }
    }
    
    bool possible = false;
    vector<vector<int>> best_summon(H, vector<int>(W));
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (check_cover_forest(forest, H, W, i, j)) {
                possible = true;
                best_summon = forest;
                break;
            }
        }
        if (possible) {
            break;
        }
    }
    
    if (!possible) {
        cout << "Impossible" << endl;
    } else {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << best_summon[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}