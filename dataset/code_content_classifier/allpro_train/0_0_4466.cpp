#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<char>> board(6, vector<char>(6));
    vector<pair<char, int>> operations;

    // Read input
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }

    // Solve puzzle
    int n = 0; // Number of operations
    // Move numbers 0-9 to the first row
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] >= '0' && board[i][j] <= '9') {
                while (j != i) {
                    if (j < i) {
                        operations.push_back({'L', i + 1});
                        j++;
                    } else {
                        operations.push_back({'R', i + 1});
                        j--;
                    }
                    n++;
                }
            }
        }
    }
    // Move characters A-Z to the bottom row
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 6; i++) {
            if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                while (i != 5) {
                    operations.push_back({'D', j + 1});
                    i++;
                    n++;
                }
            }
        }
    }

    // Print output
    cout << n << endl;
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i].first << operations[i].second << endl;
    }

    return 0;
}