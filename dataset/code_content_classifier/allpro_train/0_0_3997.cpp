#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string>& grid) {
    int balance = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '(') {
                balance++;
            } else if (grid[i][j] == ')') {
                balance--;
            }

            if (balance < 0) {
                return false;
            }
        }
    }

    return balance == 0;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<vector<int>> priorities(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> priorities[i][j];
        }
    }

    vector<string> grid(n, string(m, '('));
    k--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = ')';
            if (isValid(grid)) {
                if (k == 0) {
                    for (int x = 0; x < n; x++) {
                        cout << grid[x] << endl;
                    }
                    return 0;
                }
                k--;
            }
            grid[i][j] = '(';
        }
    }

    return 0;
}