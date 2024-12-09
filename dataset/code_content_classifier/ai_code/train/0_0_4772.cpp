#include <iostream>
#include <vector>

using namespace std;

bool isIncreasing(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][j] <= matrix[i][j-1]) {
                return false;
            }
        }
    }
    for (int j = 0; j < matrix[0].size(); j++) {
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][j] <= matrix[i-1][j]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix1(n, vector<int>(m));
    vector<vector<int>> matrix2(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix1[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    if (isIncreasing(matrix1) && isIncreasing(matrix2)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}