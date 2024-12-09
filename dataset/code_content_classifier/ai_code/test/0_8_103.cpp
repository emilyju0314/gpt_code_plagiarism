#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        int maxSteps = 0; // maximum number of steps taken
        int startRow = 1, startCol = 1; // starting position
        unordered_set<int> visited; // keep track of visited cells

        // iterate through all possible starting positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int row = i, col = j;
                int steps = 0;
                visited.clear();

                while (row >= 0 && row < n && col >= 0 && col < m && visited.find(row * m + col) == visited.end()) {
                    visited.insert(row * m + col);
                    char direction = board[row][col];
                    
                    if (direction == 'L') {
                        col--;
                    } else if (direction == 'R') {
                        col++;
                    } else if (direction == 'U') {
                        row--;
                    } else if (direction == 'D') {
                        row++;
                    }
                    
                    steps++;
                }

                if (steps > maxSteps) {
                    maxSteps = steps;
                    startRow = i + 1;
                    startCol = j + 1;
                }
            }
        }

        cout << startRow << " " << startCol << " " << maxSteps << endl;
    }

    return 0;
}