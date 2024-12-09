#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m, 0));

    // Query for the heights of all trees in the orchard
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "? " << i+1 << " " << j+1 << endl;
            fflush(stdout);
            cin >> heights[i][j];
        }
    }

    // Find the minimum height
    int min_height = heights[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            min_height = min(min_height, heights[i][j]);
        }
    }

    // Output the minimum height
    cout << "! " << min_height << endl;
    fflush(stdout);

    return 0;
}