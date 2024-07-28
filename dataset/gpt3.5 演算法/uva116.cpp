#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 100;

int matrix[MAX_ROWS][MAX_COLS];
int dp[MAX_ROWS][MAX_COLS]; // Dynamic Programming table for memoization
int path[MAX_ROWS][MAX_COLS]; // To store the path

int rows, cols;

// Function to find the minimum sum path
int minSumPath(int row, int col) {
    // Base case: If we are in the last column
    if (col == cols - 1) {
        dp[row][col] = matrix[row][col];
        return matrix[row][col];
    }

    // If the value is already calculated
    if (dp[row][col] != -1)
        return dp[row][col];

    // Calculate the minimum sum path recursively
    int minCost = INT_MAX;
    int nextRow;

    // Possible rows to move: row - 1, row, row + 1 (taking modulo to handle wrap around)
    for (int i = -1; i <= 1; ++i) {
        int newRow = (row + i + rows) % rows;
        int cost = minSumPath(newRow, col + 1) + matrix[row][col];

        if (cost < minCost || (cost == minCost && newRow < nextRow)) {
            minCost = cost;
            nextRow = newRow;
        }
    }

    // Store the next row for the path
    path[row][col] = nextRow;
    return dp[row][col] = minCost;
}

// Function to print the minimum sum path
void printPath(int start) {
    int minRow = start;
    cout << minRow + 1;

    for (int col = 1; col < cols; ++col) {
        minRow = path[minRow][col - 1];
        cout << " " << minRow + 1;
    }
    cout << endl;
}

int main() {
    while (cin >> rows >> cols) {
        // Input the matrix
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> matrix[i][j];

        // Initialize the memoization table with -1
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                dp[i][j] = -1;

        int minCost = INT_MAX;
        int startRow = -1;

        // Find the minimum sum path starting from each row
        for (int i = 0; i < rows; ++i) {
            int cost = minSumPath(i, 0);
            if (cost < minCost) {
                minCost = cost;
                startRow = i;
            }
        }

        // Print the minimum sum path starting from the row with minimum sum
        printPath(startRow);
        cout << minCost << endl;
    }

    return 0;
}
