#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int wins = 0;
    int losses = 0;
    int draws = 0;
    int totalPoints = 0;
};

int main() {
    int N;
    cin >> N;

    vector<Team> teams(N);

    for (int i = 0; i < N * (N - 1) / 2; i++) {
        int Ai, Bi, Ci, Di;
        cin >> Ai >> Bi >> Ci >> Di;

        if (Ci > Di) {
            teams[Ai - 1].wins++;
            teams[Bi - 1].losses++;
            teams[Ai - 1].totalPoints += 3;
        } else if (Ci < Di) {
            teams[Ai - 1].losses++;
            teams[Bi - 1].wins++;
            teams[Bi - 1].totalPoints += 3;
        } else {
            teams[Ai - 1].draws++;
            teams[Bi - 1].draws++;
            teams[Ai - 1].totalPoints++;
            teams[Bi - 1].totalPoints++;
        }
    }

    vector<pair<int, int>> rankings;
    for (int i = 0; i < N; i++) {
        rankings.push_back({teams[i].totalPoints, i});
    }

    sort(rankings.rbegin(), rankings.rend());

    for (int i = 0; i < N; i++) {
        cout << rankings[i].second + 1 << endl;
    }

    return 0;
}