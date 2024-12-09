#include <iostream>
#include <vector>

using namespace std;

bool isAdjacent(int a, int b) {
    return abs(a - b) == 1;
}

bool canPlaceNumber(vector<vector<int>>& matrix, int r, int c, int num) {
    int n = matrix.size();
    
    // Check left
    if (c > 0 && isAdjacent(matrix[r][c-1], num)) {
        return false;
    }
    // Check right
    if (c < n-1 && isAdjacent(matrix[r][c+1], num)) {
        return false;
    }
    // Check up
    if (r > 0 && isAdjacent(matrix[r-1][c], num)) {
        return false;
    }
    // Check down
    if (r < n-1 && isAdjacent(matrix[r+1][c], num)) {
        return false;
    }
    
    return true;
}

bool fillMatrix(vector<vector<int>>& matrix, int num) {
    int n = matrix.size();
    int r = 0, c = 0;
    
    for (int i = 1; i <= num; i++) {
        while (!canPlaceNumber(matrix, r, c, i)) {
            if (r == n-1 && c == n-1) {
                return false;
            }
            
            if (c < n-1) {
                c++;
            } else {
                r++;
                c = 0;
            }
        }
        matrix[r][c] = i;
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        if (n == 1) {
            cout << 1 << endl;
        } else if (n == 2) {
            cout << -1 << endl;
        } else {
            if (fillMatrix(matrix, n*n)) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << matrix[i][j] << " ";
                    }
                    cout << endl;
                }
            } else {
                cout << -1 << endl;
            }
        }
    }
    
    return 0;
}