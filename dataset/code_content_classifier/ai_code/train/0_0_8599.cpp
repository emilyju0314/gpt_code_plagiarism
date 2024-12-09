#include <iostream>
#include <vector>

using namespace std;

bool checkClearSymmetricalMatrix(int n, int x) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    // Construct clear symmetrical matrix
    for(int i = 0; i < n; i++) {
        matrix[i][i] = 1; // Diagonal elements
        matrix[i][n-i-1] = 1; // Anti-diagonal elements
    }
    
    // Count sharpness
    int sharpness = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sharpness += matrix[i][j];
        }
    }
    
    return sharpness == x;
}

int main() {
    int x;
    cin >> x;
    
    int n = 1;
    while(true) {
        if(checkClearSymmetricalMatrix(n, x)) {
            cout << n << endl;
            break;
        }
        n++;
    }
    
    return 0;
}