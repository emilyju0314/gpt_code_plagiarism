#include <iostream>
#include <vector>

using namespace std;

bool isValid(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    int emptyCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '.') {
                emptyCount++;
            }
        }
    }

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    string res = "UNIQUE";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '.') {
                int glaucous = 0;
                for(int k = 0; k < 4; k++) {
                    if(isValid(i + dx[k], j + dy[k], n) && grid[i + dx[k]][j + dy[k]] == 'G') {
                        glaucous++;
                    }
                }

                if(glaucous == 0 || glaucous == 4) {
                    res = "NONE";
                } else if(glaucous == 1) {
                    grid[i][j] = 'S';
                } else if(glaucous == 2) {
                    // Do nothing
                } else if(glaucous == 3) {
                    grid[i][j] = 'G';
                }
            }
        }
    }

    if(res == "NONE") {
        cout << res << endl;
    } else if(emptyCount == 0) {
        cout << "MULTIPLE" << endl;
    } else {
        cout << res << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}