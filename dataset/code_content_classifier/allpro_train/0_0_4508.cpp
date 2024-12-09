#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize a vector to store the board state
    vector<vector<int>> board(n, vector<int>(m, 1));

    int max_cells_without_spiders = 0;
    // Try all possible combinations of spider movements
    for(int command = 0; command < (1 << (n*m)); command++) {
        int count = 0;
        // Apply the commands to the board
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int pos = i*m + j;
                if(command & (1 << pos)) {
                    // Apply the command to move spiders
                    board[i][j] = 0;
                    if(i > 0) board[i-1][j] = 0;
                    if(i < n-1) board[i+1][j] = 0;
                    if(j > 0) board[i][j-1] = 0;
                    if(j < m-1) board[i][j+1] = 0;
                }
            }
        }
        // Count the number of spider-free cells after applying the commands
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1) {
                    count++;
                }
                // Reset the board state for the next iteration
                board[i][j] = 1;
            }
        }
        // Update the maximum number of spider-free cells
        max_cells_without_spiders = max(max_cells_without_spiders, count);
    }

    // Output the maximum number of spider-free cells
    cout << max_cells_without_spiders << endl;

    return 0;
}