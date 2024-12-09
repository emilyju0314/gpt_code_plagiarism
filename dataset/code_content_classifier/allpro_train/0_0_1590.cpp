#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    int min_moves = INT_MAX;

    for (int i = 0; i < n; i++) {
        int moves = 0;
        vector<int> cnt(m, 0);
        for (int j = 0; j < n; j++) {
            int diff = 0;
            for (int k = 0; k < m; k++) {
                diff += (table[j][k] != '1');
                cnt[k] += (table[j][k] == '1');
            }
            moves += diff;
        }

        bool possible = false;
        for (int k = 0; k < m; k++) {
            if (cnt[k] == n) {
                min_moves = min(min_moves, min(k, m - k));
                possible = true;
            }
        }

        if (possible) {
            min_moves = min(min_moves, moves);
        }
    }

    if (min_moves == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_moves << endl;
    }

    return 0;
}