// Here is a possible implementation in C++

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    cin >> K;
    
    // Choose n to be K+2
    int n = K+2;
    cout << n << endl;
    
    // Construct a grid of size n x n with K colors
    vector<vector<int>> grid(n, vector<int>(n));
    int color = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = color;
            color = (color % K) + 1;
        }
    }
    
    // Output the grid
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}