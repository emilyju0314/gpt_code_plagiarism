#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    int triangles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) continue; // Skip black nodes

            for (int k = i + 1; k < n; k++) {
                for (int l = j + 1; l < m; l++) {
                    if (!grid[k][l] && grid[i][l] && grid[k][j]) {
                        triangles++;
                    }
                }
            }
        }
    }

    cout << triangles << endl;

    return 0;
}