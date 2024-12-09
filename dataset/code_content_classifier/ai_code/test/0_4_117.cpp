#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(vector<vector<char>>& grid, int n, int m) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'L') {
                for(int k=0; k<4; k++) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if(isValid(newX, newY, n, m) && grid[newX][newY] == '.') {
                        grid[newX][newY] = '+';
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> grid[i][j];
            }
        }

        solve(grid, n, m);
    }

    return 0;
}