#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    char diag_char = grid[0][0];
    char off_diag_char = grid[0][1];

    bool valid = true;

    // Check diagonals
    for (int i = 0; i < n; i++) {
        if (grid[i][i] != diag_char || grid[i][n-1-i] != diag_char) {
            valid = false;
            break;
        }
    }

    // Check other squares
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i != j && i != n-1-j) && grid[i][j] != off_diag_char) {
                valid = false;
                break;
            }
        }
    }

    if (valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}