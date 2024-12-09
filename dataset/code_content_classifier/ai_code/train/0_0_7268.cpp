#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> skills(M, vector<int>(N + 1, 0));

    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;

        for (int j = 0; j < K; j++) {
            int s, t;
            string cond;
            cin >> s >> cond >> t;

            if (cond == ">=") {
                skills[i][s] = max(skills[i][s], t);
            } else {
                skills[i][s] = min(skills[i][s], t);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int minSkill = 101;
        int maxSkill = -1;

        for (int j = 0; j < M; j++) {
            minSkill = min(minSkill, skills[j][i]);
            maxSkill = max(maxSkill, skills[j][i]);
        }

        if (minSkill > maxSkill) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}