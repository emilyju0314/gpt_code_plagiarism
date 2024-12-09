#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D;
    cin >> D;

    vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
    }

    vector<vector<int>> s(D, vector<int>(26));
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < 26; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> last(26, 0);
    vector<int> contests(D);

    for (int d = 0; d < D; d++) {
        int max_increase = -1;
        int best_contest = -1;

        for (int i = 0; i < 26; i++) {
            int increase = s[d][i];
            for (int j = 0; j < 26; j++) {
                increase -= c[j] * (d - last[j]);
            }

            if (increase > max_increase) {
                max_increase = increase;
                best_contest = i + 1;
            }
        }

        contests[d] = best_contest;
        last[best_contest - 1] = d + 1;
    }

    for (int i = 0; i < D; i++) {
        cout << contests[i] << endl;
    }

    return 0;
}