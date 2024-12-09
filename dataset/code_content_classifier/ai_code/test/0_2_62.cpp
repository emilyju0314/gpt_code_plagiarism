#include <iostream>
#include <vector>
using namespace std;

int countStaircases(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                count += 2;
                if (i > 0 && matrix[i-1][j] == 1) count--;
                if (i < n-1 && matrix[i+1][j] == 1) count--;
                if (j > 0 && matrix[i][j-1] == 1) count--;
                if (j < m-1 && matrix[i][j+1] == 1) count--;
            }
        }
    }
    
    return count;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        matrix[x-1][y-1] ^= 1;
        
        cout << countStaircases(matrix) << endl;
    }
    
    return 0;
}