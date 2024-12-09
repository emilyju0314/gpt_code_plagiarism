#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> altitudes(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> altitudes[i][j];
        }
    }

    int min_diff = INT_MAX;

    // Calculate the minimum of the larger value of the difference for rows
    for (int i = 0; i < H; i++) {
        vector<int> sorted_row = altitudes[i];
        sort(sorted_row.begin(), sorted_row.end());

        int diff1 = sorted_row[W-1] - sorted_row[0];
        int diff2 = INT_MAX;

        // Calculate the differences between the max and min altitudes in the JOI and IOI regions
        for (int j = 0; j < W-1; j++) {
            int diff_joi = abs(sorted_row[j] - sorted_row[W-1]);
            int diff_ioi = abs(sorted_row[0] - sorted_row[j+1]);
            diff2 = min(diff2, max(diff_joi, diff_ioi));
        }

        min_diff = min(min_diff, max(diff1, diff2));
    }

    // Calculate the minimum of the larger value of the difference for columns
    for (int j = 0; j < W; j++) {
        vector<int> sorted_col;
        for (int i = 0; i < H; i++) {
            sorted_col.push_back(altitudes[i][j]);
        }
        sort(sorted_col.begin(), sorted_col.end());

        int diff1 = sorted_col[H-1] - sorted_col[0];
        int diff2 = INT_MAX;

        for (int i = 0; i < H-1; i++) {
            int diff_joi = abs(sorted_col[i] - sorted_col[H-1]);
            int diff_ioi = abs(sorted_col[0] - sorted_col[i+1]);
            diff2 = min(diff2, max(diff_joi, diff_ioi));
        }

        min_diff = min(min_diff, max(diff1, diff2));
    }

    cout << min_diff << endl;

    return 0;
}