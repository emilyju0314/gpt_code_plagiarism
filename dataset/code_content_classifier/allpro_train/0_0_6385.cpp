#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int max_score = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        vector<int> group(N);
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                group[i] = 1;
            }
        }

        int total_score = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (group[i] == group[j]) {
                    total_score += a[i][j];
                }
            }
        }

        max_score = max(max_score, total_score);
    }

    cout << max_score << endl;

    return 0;
}