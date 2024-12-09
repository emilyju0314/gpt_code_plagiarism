#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> pyramid(n+1, vector<int>(n+1, 0));
    vector<pair<int, int>> changed_cells;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        changed_cells.push_back({r, c});
        pyramid[r][c]++;
    }

    int operations = 0;

    for (auto cell : changed_cells) {
        int r = cell.first;
        int c = cell.second;

        for (int i = 1; i < n; i++) {
            // Find the size of the subpyramid
            int p = min(min(c-1, i), min(n-r, n-i));

            // Perform operation type 2
            operations += p+1;

            // Update the values of the subpyramid
            for (int j = i; j <= i+p; j++) {
                int top_row = r-i+1;
                int top_cell = c-(i-j);
                pyramid[top_row][top_cell]--;
            }
        }

        // Mark the cell as processed
        pyramid[r][c]--;
    }

    cout << operations << endl;

    return 0;
}