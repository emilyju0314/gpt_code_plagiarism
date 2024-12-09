#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> scores(n, 0);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            } else {
                scores[i] = max(scores[i], cnt);
                cnt = 0;
            }
        }
        scores[i] = max(scores[i], cnt);
    }

    for (int k = 0; k < q; k++) {
        int i, j;
        cin >> i >> j;
        i--;

        grid[i][j - 1] = 1 - grid[i][j - 1];

        int cnt = 0;
        int max_score = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            } else {
                max_score = max(max_score, cnt);
                cnt = 0;
            }
        }
        max_score = max(max_score, cnt);
        scores[i] = max_score;

        int overall_score = 0;
        for (int i = 0; i < n; i++) {
            overall_score = max(overall_score, scores[i]);
        }
        cout << overall_score << endl;
    }

    return 0;
}