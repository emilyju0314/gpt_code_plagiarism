#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> exitableUp(n, vector<bool>(m));
    vector<vector<bool>> exitableLeft(n, vector<bool>(m));
    
    // Input grid and preprocess exitable grids
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                exitableUp[i][j] = true;
                exitableLeft[i][j] = true;
            } else {
                exitableUp[i][j] = false;
                exitableLeft[i][j] = false;
            }
        }
    }
    
    // Update exitable grids
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (exitableUp[i][j] && exitableUp[i-1][j]) {
                exitableUp[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (exitableLeft[i][j] && exitableLeft[i][j-1]) {
                exitableLeft[i][j] = true;
            }
        }
    }
    
    int q;
    cin >> q;
    
    // Process queries
    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;
        x1--; x2--;
        
        bool determinable = true;
        for (int i = 0; i < n; i++) {
            if (exitableUp[i][x2] && exitableUp[i][x1]) {
                determinable = false;
                break;
            }
        }
        
        if (determinable) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}