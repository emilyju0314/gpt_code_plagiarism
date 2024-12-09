#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<pair<int, vector<int>>> questions(M);
        for (int i = 0; i < M; i++) {
            int Si, ki;
            cin >> Si >> ki;
            vector<int> answerers(ki);
            for (int j = 0; j < ki; j++) {
                cin >> answerers[j];
            }
            questions[i] = make_pair(Si, answerers);
        }

        int minScore = 0;
        for (int i = 0; i < M; i++) {
            minScore = max(minScore, questions[i].first);
        }

        cout << minScore << endl;
    }

    return 0;
}