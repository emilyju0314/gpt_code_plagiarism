#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                bool rowBlack = false, colBlack = false;
                for (int k = 0; k < n; k++) {
                    if (grid[k][j] == '#') {
                        colBlack = true;
                    }
                }
                for (int k = 0; k < m; k++) {
                    if (grid[i][k] == '#') {
                        rowBlack = true;
                    }
                }
                if (!rowBlack && !colBlack) {
                    possible = false;
                }
            }
        }
    }
    
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}