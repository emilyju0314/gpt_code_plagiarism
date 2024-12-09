#include <iostream>
#include <vector>

using namespace std;

bool is_unique(vector<vector<char>> &grid, int n) {
    bool sinoperAdj = true;
    bool glaucousAdj = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if ((i > 0 && grid[i-1][j] == '.') || (i < n-1 && grid[i+1][j] == '.') || (j > 0 && grid[i][j-1] == '.') || (j < n-1 && grid[i][j+1] == '.')) {
                    return false;
                }
            } else if (grid[i][j] == 'S') {
                if ((i > 0 && grid[i-1][j] == 'S') || (i < n-1 && grid[i+1][j] == 'S') || (j > 0 && grid[i][j-1] == 'S') || (j < n-1 && grid[i][j+1] == 'S')) {
                    glaucousAdj = false;
                } else {
                    sinoperAdj = false;
                }
            } else if (grid[i][j] == 'G') {
                if ((i > 0 && grid[i-1][j] == 'G') || (i < n-1 && grid[i+1][j] == 'G') || (j > 0 && grid[i][j-1] == 'G') || (j < n-1 && grid[i][j+1] == 'G')) {
                    sinoperAdj = false;
                } else {
                    glaucousAdj = false;
                }
            }
        }
    }
    
    return sinoperAdj || glaucousAdj;
}

bool can_be_mastapeece(vector<vector<char>> grid, int n, char color, int i, int j) {
    
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '.') {
        return true;
    }
    
    if (grid[i][j] == color) {
        return false;
    }
    
    grid[i][j] = color;
    
    return can_be_mastapeece(grid, n, color, i+1, j) && can_be_mastapeece(grid, n, color, i-1, j) && 
           can_be_mastapeece(grid, n, color, i, j+1) && can_be_mastapeece(grid, n, color, i, j-1);
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<char>> grid(n, vector<char>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    if (!is_unique(grid, n)) {
        cout << "MULTIPLE" << endl;
    } else if (!can_be_mastapeece(grid, n, 'S', 0, 0) && !can_be_mastapeece(grid, n, 'G', 0, 0)) {
        cout << "NONE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}