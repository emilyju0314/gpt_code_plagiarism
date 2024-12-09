#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pairs(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }

    vector<int> teams(n, 0);
    vector<vector<int>> teamMembers(n / 3, vector<int>(3, 0));

    for (int i = 1; i <= n / 3; i++) {
        teamMembers[i - 1][0] = i;
        teamMembers[i - 1][1] = i + n / 3;
        teamMembers[i - 1][2] = i + 2 * n / 3;
    }

    for (int i = 0; i < m; i++) {
        int a = pairs[i].first;
        int b = pairs[i].second;

        if (teams[a - 1] != 0 && teams[b - 1] != 0) {
            if (teams[a - 1] == teams[b - 1]) {
                cout << -1 << endl;
                return 0;
            }
            continue;
        }

        int team;
        if (teams[a - 1] != 0) {
            team = teams[a - 1];
        } else if (teams[b - 1] != 0) {
            team = teams[b - 1];
        } else {
            team = teams[a - 1] = teams[b - 1] = min(teams[a - 1], teams[b - 1]);
        }

        for (int j = 0; j < n / 3; j++) {
            if (teamMembers[j][0] == a || teamMembers[j][1] == a || teamMembers[j][2] == a) {
                teamMembers[j][0] = a;
                teamMembers[j][1] = b;
                teams[b - 1] = team;
                break;
            }
        }
    }

    for (int i = 0; i < n / 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << teamMembers[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}