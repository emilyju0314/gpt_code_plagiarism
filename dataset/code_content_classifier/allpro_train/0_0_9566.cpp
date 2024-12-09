#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<vector<int>> t(3, vector<int>(3));
    int n;
    
    // Input matrix t
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> t[i][j];
        }
    }
    
    // Input n
    cin >> n;
    
    // Minimum cost calculation
    int totalCost = 0;
    for(int i = 0; i < n; i++) {
        totalCost += t[0][1] + t[0][2] + t[1][2];
    }
    
    // Output
    cout << totalCost << endl;
    
    return 0;
}