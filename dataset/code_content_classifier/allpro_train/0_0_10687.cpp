#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    int moves = 0;
    for (int i = 0; i < n; i++) {
        bool dwarfFound = false;
        bool candyFound = false;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'G') {
                dwarfFound = true;
            } else if (matrix[i][j] == 'S') {
                candyFound = true;
            }
        }
        if (dwarfFound && !candyFound) {
            moves++;
        }
    }

    bool success = true;
    for (int j = 0; j < m; j++) {
        bool dwarfFound = false;
        bool candyFound = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 'G') {
                dwarfFound = true;
            } else if (matrix[i][j] == 'S') {
                candyFound = true;
            }
        }
        if (dwarfFound && !candyFound) {
            success = false;
            break;
        }
    }

    if (success) {
        cout << moves << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}