#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<bool>> isSea(r, vector<bool>(c, true));
    unordered_set<int> topCells;
    unordered_set<int> bottomCells;

    for (int i = 0; i < n; i++) {
        int row, col;
        cin >> row >> col;

        // Check if the current cell can be turned into land
        bool isValid = true;
        
        // Check if the cell is on the top row
        if (row == 1) {
            if (topCells.count(col) == 0) {
                topCells.insert(col);
            } else {
                isValid = false;
            }
        }

        // Check if the cell is on the bottom row
        if (row == r) {
            if (bottomCells.count(col) == 0) {
                bottomCells.insert(col);
            } else {
                isValid = false;
            }
        }

        // Check if the cell can be turned into land without violating the trade route condition
        if (!isValid) {
            continue;
        }

        isSea[row - 1][col - 1] = false;
    }

    int count = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!isSea[i - 1][j - 1]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}