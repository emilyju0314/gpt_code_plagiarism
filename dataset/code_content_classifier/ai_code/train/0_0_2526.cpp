#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    // Step 1: Fill the grid with integers from 0 to (n^2 - 1) inclusive
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = num++;
        }
    }

    // Step 2: Apply XOR operation on each row to get the desired XOR value for each row
    for (int i = 0; i < n; i++) {
        int row_xor = 0;
        for (int j = 0; j < n; j++) {
            row_xor ^= grid[i][j];
        }
        for (int j = 0; j < n; j++) {
            grid[i][j] = row_xor;
        }
    }

    // Step 3: Apply XOR operation on each column to get the desired XOR value for each column
    for (int j = 0; j < n; j++) {
        int col_xor = 0;
        for (int i = 0; i < n; i++) {
            col_xor ^= grid[i][j];
        }
        for (int i = 0; i < n; i++) {
            grid[i][j] = col_xor;
        }
    }

    // Output the magic grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}