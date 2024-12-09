#include <iostream>
#include <vector>

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int count = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (matrix[r][c] == 1) {
                for (int side = 1; r + side < n && c + side < m; side++) {
                    bool validSquare = true;
                    for (int i = 0; i <= side; i++) {
                        if (matrix[r + i][c + side] == 0 || matrix[r + side][c + i] == 0) {
                            validSquare = false;
                            break;
                        }
                    }
                    if (validSquare) {
                        count++;
                    }
                }
            }
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> matrix(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                matrix[i][j] = c - '0';
            }
        }
        
        cout << countSquares(matrix) << endl;
    }
    
    return 0;
}