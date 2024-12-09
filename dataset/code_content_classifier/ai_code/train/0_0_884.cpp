#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool possible = true;
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool south = false;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                south = true;
                break;
            }
        }
        if (!south) {
            possible = false;
            break;
        }
    }

    for (int j = 0; j < m; j++) {
        bool south = false;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '#') {
                south = true;
                break;
            }
        }
        if (!south) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int black_cells = 0;
                if (grid[i][j] == '#') {
                    for (int k = 0; k < n; k++) {
                        if (grid[k][j] == '#') black_cells++;
                    }
                    for (int k = 0; k < m; k++) {
                        if (grid[i][k] == '#') black_cells++;
                    }
                    if (black_cells == 2) count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}