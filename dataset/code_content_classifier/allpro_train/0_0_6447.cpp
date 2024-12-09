#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> rows(n);
    for (int i = 0; i < n; i++) {
        cin >> rows[i];
    }

    vector<int> columns(m);
    for (int i = 0; i < m; i++) {
        cin >> columns[i];
    }

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    for (int i = 0; i < n; i++) {
        int blackSegments = rows[i];
        for (int j = 0; j < blackSegments; j++) {
            grid[i][j] = '*';
        }
    }

    for (int i = 0; i < m; i++) {
        int blackSegments = columns[i];
        for (int j = 0; j < blackSegments; j++) {
            grid[j][i] = '*';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}