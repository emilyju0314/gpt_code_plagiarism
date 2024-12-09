#include <iostream>
#include <vector>
#include <string>

using namespace std;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();
    int response;
    cin >> response;
    return response;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == -1) {
                if (i < n - 1 && query(i, j, i + 1, j)) {
                    grid[i][j] = grid[i+1][j];
                } else if (j < n - 1 && query(i, j, i, j + 1)) {
                    grid[i][j] = grid[i][j+1];
                }
            }
        }
    }

    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}