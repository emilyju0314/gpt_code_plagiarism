#include <iostream>
#include <vector>

using namespace std;

bool isValidTick(vector<vector<char>>& field, int i, int j, int k) {
    int n = field.size();
    int m = field[0].size();
    // Check if the center cell is already black
    if (field[i][j] != '*') {
        return false;
    }
    
    // Check if the tick of size k with center at (i, j) is valid
    for (int h = 0; h <= k; h++) {
        if (i - h < 0 || i + h >= n || j - h < 0 || j + h >= m) {
            return false;
        }
        if (field[i - h][j - h] != '*' || field[i - h][j + h] != '*') {
            return false;
        }
    }
    
    return true;
}

bool checkField(vector<vector<char>>& field, int k) {
    int n = field.size();
    int m = field[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isValidTick(field, i, j, k)) {
                // Mark the cells of the tick as visited
                for (int h = 0; h <= k; h++) {
                    field[i - h][j - h] = '.';
                    field[i - h][j + h] = '.';
                }
                field[i][j] = '.';
            }
        }
    }
    
    // Check if all cells are visited
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<vector<char>> field(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }
        
        if (checkField(field, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}