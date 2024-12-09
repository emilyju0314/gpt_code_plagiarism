#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    set<pair<int, int>> blackPixels;

    for (int move = 1; move <= k; move++) {
        int i, j;
        cin >> i >> j;
        i--; j--;

        grid[i][j] = 1;
        blackPixels.insert({i, j});

        if (i > 0 && j > 0) {
            if (blackPixels.count({i-1, j}) && blackPixels.count({i, j-1}) && blackPixels.count({i-1, j-1})) {
                cout << move << endl;
                return 0;
            }
        }
        
        if (i > 0 && j < m-1) {
            if (blackPixels.count({i-1, j}) && blackPixels.count({i, j+1}) && blackPixels.count({i-1, j+1})) {
                cout << move << endl;
                return 0;
            }
        }
        
        if (i < n-1 && j > 0) {
            if (blackPixels.count({i+1, j}) && blackPixels.count({i, j-1}) && blackPixels.count({i+1, j-1})) {
                cout << move << endl;
                return 0;
            }
        }
        
        if (i < n-1 && j < m-1) {
            if (blackPixels.count({i+1, j}) && blackPixels.count({i, j+1}) && blackPixels.count({i+1, j+1})) {
                cout << move << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;

    return 0;
}