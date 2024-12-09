#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<int> row_flips(n, 0);
    vector<int> col_flips(m, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != (i + j) % 2) {
                row_flips[i]++;
                col_flips[j]++;
            }
        }
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (row_flips[i] % 2 != 0) {
            possible = false;
        }
    }
    
    for (int j = 0; j < m; j++) {
        if (col_flips[j] % 2 != 0) {
            possible = false;
        }
    }
    
    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        for (int i = 0; i < n; i++) {
            cout << "0";
        }
        cout << endl;
        
        for (int j = 0; j < m; j++) {
            cout << "0";
        }
        cout << endl;
    }
    
    return 0;
}