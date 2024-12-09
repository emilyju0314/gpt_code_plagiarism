#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, M;
    cin >> H >> W >> M;

    vector<int> row_targets(H+1, 0);
    vector<int> col_targets(W+1, 0);
    vector<pair<int, int>> targets(M);

    for (int i = 0; i < M; i++) {
        int h, w;
        cin >> h >> w;
        targets[i] = {h, w};
        row_targets[h]++;
        col_targets[w]++;
    }

    int max_row = *max_element(row_targets.begin(), row_targets.end());
    int max_col = *max_element(col_targets.begin(), col_targets.end());

    int max_targets = max_row + max_col;

    int max_row_count = count(row_targets.begin(), row_targets.end(), max_row);
    int max_col_count = count(col_targets.begin(), col_targets.end(), max_col);

    for (auto target : targets) {
        if (row_targets[target.first] == max_row && col_targets[target.second] == max_col) {
            max_targets--;
            break;
        }
    }

    cout << max_targets << endl;

    return 0;
}