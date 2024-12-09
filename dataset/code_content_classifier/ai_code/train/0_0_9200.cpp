#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tiles(n, vector<int>(n));
    vector<vector<int>> contrast(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tiles[i][j];
        }
    }

    // Calculate the contrast for each non-broken tile
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (tiles[i][j] == 0) {
                int min_contrast = abs(tiles[i-1][j] - tiles[i][j]) + abs(tiles[i+1][j] - tiles[i][j])
                                 + abs(tiles[i][j-1] - tiles[i][j]) + abs(tiles[i][j+1] - tiles[i][j]);
                contrast[i][j] = min_contrast;
            }
        }
    }

    // Compute the minimum total contrast
    int min_total_contrast = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            min_total_contrast += contrast[i][j];
        }
    }

    cout << min_total_contrast << endl;

    return 0;
}