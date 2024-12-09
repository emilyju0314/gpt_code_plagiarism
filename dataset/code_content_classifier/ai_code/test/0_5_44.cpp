#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    char grid[n][n];
    int countS = 0, countG = 0;
    bool cannot = false, unique = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                countS++;
            } else if (grid[i][j] == 'G') {
                countG++;
            }
        }
    }

    if (countS == 0 && countG == 0) {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "S";
            }
            cout << endl;
        }
        return 0;
    }

    if (countS == 0 || countG == 0) {
        cout << "NONE" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if (i > 0 && grid[i-1][j] == grid[i+1][j] && grid[i+1][j] != '.') {
                    cannot = true;
                    unique = false;
                    break;
                }
                if (j > 0 && grid[i][j-1] == grid[i][j+1] && grid[i][j+1] != '.') {
                    cannot = true;
                    unique = false;
                    break;
                }
            }
        }
    }

    if (cannot) {
        cout << "NONE" << endl;
    } else if (unique) {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    cout << "S";
                } else {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    } else {
        cout << "MULTIPLE" << endl;
    }

    return 0;
}