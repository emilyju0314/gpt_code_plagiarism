#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;

int minManhattanDist(int x, int y, int target) {
    int minDist = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == target) {
                minDist = min(minDist, abs(x - i) + abs(y - j));
            }
        }
    }
    
    return minDist;
}

int solve() {
    int minDist2 = INT_MAX, minDist3 = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                minDist2 = min(minDist2, minManhattanDist(i, j, 3));
            } else if (grid[i][j] == 3) {
                minDist3 = min(minDist3, minManhattanDist(i, j, 2));
            }
        }
    }
    
    return minDist2*2 + minDist3*2;
}

int main() {
    while (true) {
        cin >> n >> m;
        
        if (n == 0 && m == 0) {
            break;
        }
        
        grid = vector<vector<int>>(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        cout << solve() << endl;
    }
    
    return 0;
}