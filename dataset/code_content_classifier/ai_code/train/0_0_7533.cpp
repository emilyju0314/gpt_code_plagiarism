#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int size, vector<string>& grid) {
    for (int i = x - size; i <= x + size; i++) {
        for (int j = y - size; j <= y + size; j++) {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '*') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> stars;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (grid[i][j] == '*') {
                int size = 1;
                while (isValid(i, j, size, grid)) {
                    stars.push_back({i+1, j+1, size});
                    size++;
                }
            }
        }
    }

    if (stars.empty()) {
        cout << -1 << endl;
    } else {
        cout << stars.size() << endl;
        for (auto star : stars) {
            cout << star[0] << " " << star[1] << " " << star[2] << endl;
        }
    }

    return 0;
}