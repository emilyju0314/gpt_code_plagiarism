#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string horizontal_directions, vertical_directions;

    cin >> horizontal_directions;
    cin >> vertical_directions;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (horizontal_directions[i] == '<' && j > 0) {
                grid[i][j] += grid[i][j - 1] + 1;
            }
            if (horizontal_directions[i] == '>' && j < m - 1) {
                grid[i][j] += grid[i][j + 1] + 1;
            }
            if (vertical_directions[j] == '^' && i > 0) {
                grid[i][j] += grid[i - 1][j] + 1;
            }
            if (vertical_directions[j] == 'v' && i < n - 1) {
                grid[i][j] += grid[i + 1][j] + 1;
            }
        }
    }

    bool possible = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != (n-1) + (m-1) - 1) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}