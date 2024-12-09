#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> grid(2, vector<int>(n, 0));
    unordered_set<int> blockedCols;
    int reachable = 0;

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;

        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            if (grid[1 - r][c] == 1) reachable--;
        } else {
            grid[r][c] = 1;
            if (grid[1 - r][c] == 1) reachable++;
        }

        if (c > 0) {
            if (grid[1][c-1] == 1) {
                if (grid[0][c-1] == 1 || grid[0][c] == 1 || grid[1][c] == 1) {
                    if (blockedCols.find(c) == blockedCols.end()) {
                        blockedCols.insert(c);
                        reachable--;
                    }
                } else {
                    if (blockedCols.find(c) != blockedCols.end()) {
                        blockedCols.erase(c);
                        reachable++;
                    }
                }
            }
        }

        if (c < n-1) {
            if (grid[1][c+1] == 1) {
                if (grid[0][c+1] == 1 || grid[0][c] == 1 || grid[1][c] == 1) {
                    if (blockedCols.find(c+1) == blockedCols.end()) {
                        blockedCols.insert(c+1);
                        reachable--;
                    }
                } else {
                    if (blockedCols.find(c+1) != blockedCols.end()) {
                        blockedCols.erase(c+1);
                        reachable++;
                    }
                }
            }
        }
        
        if (reachable > 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}