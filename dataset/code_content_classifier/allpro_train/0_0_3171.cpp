#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> matrix(n, vector<int>(m));
    vector<int> ones_count(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) ones_count[j]++;
        }
    }

    int max_score = 0;
    int min_replacements = 0;

    for (int j = 0; j < m; j++) {
        int curr_score = 0;
        int replacements = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 1) {
                int ones_in_range = 0;
                for (int l = i; l < min(i + k, n); l++) {
                    if (matrix[l][j] == 1) ones_in_range++;
                }
                if (ones_in_range > curr_score) {
                    curr_score = ones_in_range;
                    replacements = ones_count[j] - curr_score;
                }
            }
        }
        max_score += curr_score;
        min_replacements += replacements;
    }

    cout << max_score << " " << min_replacements << endl;

    return 0;
}