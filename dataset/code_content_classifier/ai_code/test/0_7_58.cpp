#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPossibleToComplete(int n, vector<string>& grid) {
    int currentRow = 1;
    int currentCol = 1;

    while (currentCol < n) {
        if (currentRow == 1) {
            if (grid[currentRow][currentCol] == '1' || grid[2][currentCol + 1] == '1') {
                return false;
            }
        } else {
            if (grid[currentRow][currentCol] == '1' || grid[1][currentCol + 1] == '1') {
                return false;
            }
        }

        currentCol++;
        currentRow = 3 - currentRow; // Switches between row 1 and row 2
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(3);
        cin >> grid[1];
        cin >> grid[2];

        if (isPossibleToComplete(n, grid)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}