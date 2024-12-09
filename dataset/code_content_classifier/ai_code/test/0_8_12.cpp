#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(m+1, 0));
    vector<vector<int>> nearest_pole(n+1, vector<int>(m+1, 0));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int min_dist = n*m; // set to maximum possible distance
            for(int x = 0; x <= n; x++) {
                for(int y = 0; y <= m; y++) {
                    if(grid[x][y] == 1) {
                        int dist = (x-i)*(x-i) + (y-j)*(y-j);
                        min_dist = min(min_dist, dist);
                    }
                }
            }
            nearest_pole[i][j] = min_dist;
        }
    }

    int sum = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            sum += nearest_pole[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}