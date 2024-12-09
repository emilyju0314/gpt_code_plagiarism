#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> treasures(k);
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        treasures[i] = make_pair(r, c);
    }

    vector<int> safe_columns(q);
    for (int i = 0; i < q; i++) {
        cin >> safe_columns[i];
    }

    sort(treasures.begin(), treasures.end());

    int min_moves = INT_MAX;
    for (int i = 0; i < q; i++) {
        int start_col = safe_columns[i];
        int current_col = start_col;
        int moves = 0;
        for (int j = 0; j < k; j++) {
            moves += abs(treasures[j].second - current_col);
            moves += treasures[j].first - 1;
            current_col = treasures[j].second;
        }
        min_moves = min(min_moves, moves);
    }

    cout << min_moves << endl;

    return 0;
}