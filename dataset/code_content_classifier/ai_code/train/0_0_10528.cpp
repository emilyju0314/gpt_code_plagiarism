#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    int rowSum = 0, colSum = 0, mainDiagSum = 0, secDiagSum = 0;
    int emptyRow, emptyCol;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 0) {
                emptyRow = i;
                emptyCol = j;
            }
        }
    }

    // Calculate the sums of rows, columns, and diagonals
    for(int i = 0; i < n; i++) {
        rowSum = 0, colSum = 0;
        for(int j = 0; j < n; j++) {
            rowSum += grid[i][j];
            colSum += grid[j][i];
            if(i == j) mainDiagSum += grid[i][j];
            if(i + j == n - 1) secDiagSum += grid[i][j];
        }
        if(rowSum != 0 && colSum != 0 && rowSum == colSum) {
            continue;
        } else {
            cout << "-1" << endl;
            return 0;
        }
    }

    // Calculate the number to be filled in the empty cell
    int num = mainDiagSum - rowSum;

    // Check if the number is positive and doesn't duplicate in the grid
    if(num <= 0) {
        cout << "-1" << endl;
    } else {
        grid[emptyRow][emptyCol] = num;
        cout << num << endl;
    }

    return 0;
}