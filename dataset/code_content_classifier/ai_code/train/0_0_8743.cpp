#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> ans;

    for (int i = 0; i < N; i += 2) {
        for (int j = 0; j < N; j += 2) {
            if (grid[i][j] == 'o') {
                ans.push_back({i+1, j+1});
                if (i+1 < N) grid[i+1][j] = (grid[i+1][j] == 'o') ? 'x' : 'o';
                if (i-1 >= 0) grid[i-1][j] = (grid[i-1][j] == 'o') ? 'x' : 'o';
                if (j+1 < N) grid[i][j+1] = (grid[i][j+1] == 'o') ? 'x' : 'o';
                if (j-1 >= 0) grid[i][j-1] = (grid[i][j-1] == 'o') ? 'x' : 'o';
            }
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (auto p : ans) {
            cout << p[0] << " " << p[1] << endl;
        }
    }

    return 0;
}