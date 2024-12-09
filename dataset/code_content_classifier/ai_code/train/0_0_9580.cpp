#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    long long balloons;
    long long weight;
};

bool compare(Team a, Team b) {
    return a.balloons > b.balloons;
}

int main() {
    int n;
    cin >> n;

    vector<Team> teams(n);
    long long limakBalloons, limakWeight;

    for (int i = 0; i < n; i++) {
        cin >> teams[i].balloons >> teams[i].weight;
    }

    sort(teams.begin(), teams.end(), compare);

    limakBalloons = teams[0].balloons;
    limakWeight = teams[0].weight;

    int limakPlace = 1;

    for (int i = 1; i < n; i++) {
        if (limakBalloons > limakWeight) {
            break;
        }

        if (teams[i].balloons > limakBalloons) {
            limakPlace = i + 1;
            limakWeight += teams[i].weight;
        }
    }

    cout << limakPlace << endl;

    return 0;
}