#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> grid;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool hasAdjacentSameColor(int i, int j, char color) {
    int count = 0;
    if (isValid(i-1, j) && grid[i-1][j] == color) {
        count++;
    }
    if (isValid(i+1, j) && grid[i+1][j] == color) {
        count++;
    }
    if (isValid(i, j-1) && grid[i][j-1] == color) {
        count++;
    }
    if (isValid(i, j+1) && grid[i][j+1] == color) {
        count++;
    }
    return count == 2;
}

int main() {
    cin >> n;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool unique = true;
    bool hasEmpty = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                hasEmpty = true;
                if (!hasAdjacentSameColor(i, j, 'S') && !hasAdjacentSameColor(i, j, 'G')) {
                    unique = false;
                    break;
                }
            }
        }
    }

    if (!hasEmpty) {
        cout << "NONE" << endl;
    } else if (!unique) {
        cout << "MULTIPLE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    if (hasAdjacentSameColor(i, j, 'S')) {
                        cout << 'S';
                    } else {
                        cout << 'G';
                    }
                } else {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}