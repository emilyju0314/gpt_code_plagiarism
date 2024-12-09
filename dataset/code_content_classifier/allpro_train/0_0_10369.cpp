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

    vector<int> t(D);
    for (int i = 0; i < D; i++) {
        cin >> t[i];
    }

    int last_day[26] = {0};
    int total_satisfaction = 0;

    for (int i = 0; i < D; i++) {
        total_satisfaction += s[i][t[i] - 1];

        for (int j = 0; j < 26; j++) {
            last_day[j]++;
            if (j == t[i] - 1) {
                last_day[j] = 0;
            }

            total_satisfaction -= c[j] * last_day[j];
        }

        cout << total_satisfaction << endl;
    }

    return 0;
}