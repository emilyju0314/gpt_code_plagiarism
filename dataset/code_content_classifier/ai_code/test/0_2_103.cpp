#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Read the board input
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        // Initialize variables to keep track of the max number of moves and the starting position
        int max_moves = 0;
        int start_row = 1, start_col = 1;

        // Iterate through each cell in the board 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Initialize variables for current cell, current moves, current row, and current column
                char direction = board[i][j];
                int moves = 0;
                int curr_row = i, curr_col = j;

                // Initialize visited array to keep track of visited cells
                vector<vector<bool>> visited(n, vector<bool>(m, false));

                // Keep track of visited cells and calculate the number of moves until the robot breaks or stops
                while (!visited[curr_row][curr_col]) {
                    visited[curr_row][curr_col] = true;
                    moves++;

                    // Move the robot according to the direction on the current cell
                    if (direction == 'L') {
                        curr_col--;
                    } else if (direction == 'R') {
                        curr_col++;
                    } else if (direction == 'D') {
                        curr_row++;
                    } else if (direction == 'U') {
                        curr_row--;
                    }

                    // Check if the robot moved beyond the board
                    if (curr_row < 0 || curr_col < 0 || curr_row >= n || curr_col >= m) {
                        break;
                    }

                    // Update the direction to the next cell
                    direction = board[curr_row][curr_col];
                }

                // Update the maximum number of moves and starting position if needed
                if (moves > max_moves) {
                    max_moves = moves;
                    start_row = i+1;
                    start_col = j+1;
                }
            }
        }

        // Output the result for the test case
        cout << start_row << " " << start_col << " " << max_moves << endl;
    }

    return 0;
}