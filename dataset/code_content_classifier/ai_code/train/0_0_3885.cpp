#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, R, L;
    cin >> N >> R >> L;

    vector<vector<pair<int, int>>> teams(N + 1); // Vector to store team scores and timestamps

    int currTeam = 1;
    int currTime = 0;
    int maxTime = 0;
    int maxTeam = 1;

    for (int i = 0; i < R; i++) {
        int d, t, x;
        cin >> d >> t >> x;

        teams[d].push_back({t, x});

        while (teams[currTeam].empty() || teams[currTeam].back().first < currTime) {
            currTeam++;
            if (currTeam > N) currTeam = 1;
        }

        int totalTime = 0;
        for (int j = currTeam; j <= N; j++) {
            if (!teams[j].empty() && teams[j].back().first >= currTime) {
                totalTime += min(teams[j].back().first, (int)L) - currTime;
            }
        }

        if (totalTime > maxTime) {
            maxTime = totalTime;
            maxTeam = currTeam;
        }

        currTime = t;
    }

    cout << maxTeam << endl;

    return 0;
}