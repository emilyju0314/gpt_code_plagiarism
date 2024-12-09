#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(m+1));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    vector<vector<int>> nearest_pole_dist(n+1, vector<int>(m+1, INT_MAX));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(grid[i][j] == 1) {
                nearest_pole_dist[i][j] = 0;
            }
            else {
                for(int x = 0; x <= n; x++) {
                    for(int y = 0; y <= m; y++) {
                        if(grid[x][y] == 1) {
                            int dist = (x-i)*(x-i) + (y-j)*(y-j);
                            nearest_pole_dist[i][j] = min(nearest_pole_dist[i][j], dist);
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            sum += nearest_pole_dist[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}