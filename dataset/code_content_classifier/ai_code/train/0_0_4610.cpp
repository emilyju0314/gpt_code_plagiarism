#include <iostream>
#include <vector>

using namespace std;

void makeDraw(int n, vector<string>& grid) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '.') {
                k++;
            }
        }
    }

    int operations = k/3;
    char target = 'X';
    if (k % 3 == 1) {
        target = 'O';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '.' && operations > 0) {
                grid[i][j] = target;
                operations--;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        makeDraw(n, grid);

        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }
    }

    return 0;
}