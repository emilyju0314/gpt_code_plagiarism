#include <iostream>
#include <vector>

using namespace std;

bool isBeingawesomeism(vector<string>& grid, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'P') {
                return false;
            }
        }
    }
    return true;
}

int minUsages(vector<string>& grid, int r, int c) {
    if (isBeingawesomeism(grid, r, c)) {
        return 0;
    }

    for (int x = 1; x <= r; x++) {
        for (int i = 0; i + x <= r; i++) {
            for (int j = 0; j < c; j++) {
                vector<string> tempGrid = grid;

                for (int k = i; k < i + x; k++) {
                    tempGrid[k][j] = 'A';
                }

                if (isBeingawesomeism(tempGrid, r, c)) {
                    return x;
                }
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;

        vector<string> grid(r);
        for (int i = 0; i < r; i++) {
            cin >> grid[i];
        }

        int result = minUsages(grid, r, c);
        if (result == -1) {
            cout << "MORTAL" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}