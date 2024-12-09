#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> stars(n, vector<int>(m, -1));

    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(grid[i][j] == '*' && grid[i-1][j] == '*' && grid[i+1][j] == '*' && grid[i][j-1] == '*' && grid[i][j+1] == '*') {
                stars[i][j] = 1;
                stars[i-1][j] = 2;
                stars[i+1][j] = 2;
                stars[i][j-1] = 2;
                stars[i][j+1] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*' && stars[i][j] == -1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int num_stars = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(stars[i][j] > 0) {
                num_stars++;
            }
        }
    }

    cout << num_stars << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(stars[i][j] > 0) {
                cout << i+1 << " " << j+1 << " " << stars[i][j] << endl;
            }
        }
    }

    return 0;
}