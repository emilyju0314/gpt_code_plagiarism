#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int currentCell = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = currentCell;
            currentCell = currentCell == k ? 1 : currentCell + 1;
        }
    }

    for (int i = 0; i < k; i++) {
        cout << 4 << " ";
        int row = i / m;
        int col = i % m;
        cout << row + 1 << " " << col + 1 << " ";
        cout << row + 2 << " " << col + 1 << " ";
        cout << row + 1 << " " << col + 2 << " ";
        cout << row + 2 << " " << col + 2 << endl;
    }

    return 0;
}