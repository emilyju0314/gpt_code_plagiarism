#include <iostream>
#include <vector>

using namespace std;

bool isValid(char currentColor, char nextColor) {
    if (currentColor == 'S' && nextColor == 'S') return false;
    if (currentColor == 'G' && nextColor == 'G') return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<char>> result(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            result[i][j] = '.';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '.') continue;

            char possibleColor = 'S';
            bool canBeSinoper = true;
            bool canBeGlaucous = true;

            if (i > 0 && grid[i-1][j] != '.') {
                if (grid[i-1][j] == 'S') canBeGlaucous = false;
                else canBeSinoper = false;
            }

            if (i < n-1 && grid[i+1][j] != '.') {
                if (grid[i+1][j] == 'S') canBeGlaucous = false;
                else canBeSinoper = false;
            }

            if (j > 0 && grid[i][j-1] != '.') {
                if (grid[i][j-1] == 'S') canBeGlaucous = false;
                else canBeSinoper = false;
            }

            if (j < n-1 && grid[i][j+1] != '.') {
                if (grid[i][j+1] == 'S') canBeGlaucous = false;
                else canBeSinoper = false;
            }

            if (!canBeSinoper && !canBeGlaucous) {
                cout << "NONE" << endl;
                return 0;
            }

            if (canBeSinoper) result[i][j] = 'S';
            else if (canBeGlaucous) result[i][j] = 'G';
        }
    }

    bool multiple = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] == '.') {
                if (isValid(result[i-1][j], result[i+1][j]) && isValid(result[i][j-1], result[i][j+1])) {
                    multiple = true;
                    break;
                }
            }
        }
        if (multiple) break;
    }

    if (multiple) {
        cout << "MULTIPLE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << result[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}