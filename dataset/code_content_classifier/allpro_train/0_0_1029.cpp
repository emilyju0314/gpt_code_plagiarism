#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<pair<int, int>> teams(N+1, {0, 0}); // scores of teams, index 0 is not used

    for (int i = 0; i < C; i++) {
        int command;
        cin >> command;

        if (command == 0) {
            int t, p;
            cin >> t >> p;
            teams[t].second += p; // update the score of team t
        } else if (command == 1) {
            int m;
            cin >> m;

            // calculate the ranking of teams based on scores
            vector<int> rankings;
            for (int j = 1; j <= N; j++) {
                rankings.push_back(teams[j].second);
            }
            sort(rankings.begin(), rankings.end(), greater<int>());

            // output the team number and score of the team with the specified rank m
            for (int j = 1; j <= N; j++) {
                if (teams[j].second == rankings[m-1]) {
                    cout << j << " " << teams[j].second << endl;
                    break;
                }
            }
        }
    }

    return 0;
}