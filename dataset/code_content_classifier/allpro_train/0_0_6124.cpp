#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D, G;
    cin >> D >> G;

    vector<int> p(D), c(D);
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
    }

    int ans = INT_MAX;

    for (int mask = 0; mask < (1 << D); mask++) {
        int solved = 0;
        int score = 0;
        int total_problems = 0;

        for (int i = 0; i < D; i++) {
            if (mask & (1 << i)) {
                solved += p[i];
                score += 100 * (i + 1) * p[i] + c[i];
            } else {
                total_problems = i + 1;
            }
        }

        if (score < G) {
            int remaining = G - score;
            int max_score = 100 * total_problems;

            if (remaining % max_score == 0) {
                solved += remaining / max_score;
            } else {
                solved += remaining / max_score + 1;
            }
        }

        ans = min(ans, solved);
    }

    cout << ans << endl;

    return 0;
}