#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int bricks = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (j == 0 || j == m-1 || i == n-1 || grid[i][j+1] == '.' || grid[i+1][j] == '.') {
                    bricks++;
                }
            }
        }
    }

    cout << bricks << endl;

    return 0;
}