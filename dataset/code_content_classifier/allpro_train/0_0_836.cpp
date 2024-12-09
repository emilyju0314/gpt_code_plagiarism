#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool possible = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                bool row_black = false;
                bool col_black = false;

                for(int k = 0; k < n; k++) {
                    if(grid[k][j] == '#') {
                        col_black = true;
                        break;
                    }
                }

                for(int k = 0; k < m; k++) {
                    if(grid[i][k] == '#') {
                        row_black = true;
                        break;
                    }
                }

                if(!row_black && !col_black) {
                    possible = false;
                    break;
                }
            }
        }
    }

    if(possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}