#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        vector<int> scores(N);
        for (int i = 0; i < N; i++) {
            cin >> scores[i];
        }

        int max_score = 0;

        for (int i = 0; i < (1 << N); i++) {
            int total_score = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    total_score += scores[j];
                }
            }
            if (total_score <= M) {
                max_score = max(max_score, total_score);
            }
        }

        cout << max_score << endl;
    }

    return 0;
}