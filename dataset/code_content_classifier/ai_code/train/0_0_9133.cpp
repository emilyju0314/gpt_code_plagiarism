#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countWays(vector<int>& difficulties, int n, int l, int r, int x) {
    int ways = 0;
    int total_difficulty, min_difficulty, max_difficulty;

    for (int i = 1; i < (1 << n); i++) {
        total_difficulty = 0;
        min_difficulty = INT_MAX;
        max_difficulty = INT_MIN;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total_difficulty += difficulties[j];
                min_difficulty = min(min_difficulty, difficulties[j]);
                max_difficulty = max(max_difficulty, difficulties[j]);
            }
        }

        if (total_difficulty >= l && total_difficulty <= r &&
            max_difficulty - min_difficulty >= x) {
            ways++;
        }
    }

    return ways;
}

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> difficulties(n);
    for (int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }

    int ways = countWays(difficulties, n, l, r, x);
    cout << ways << endl;

    return 0;
}