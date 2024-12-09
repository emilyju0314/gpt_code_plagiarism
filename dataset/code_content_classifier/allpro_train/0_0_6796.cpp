#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> results(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        cin >> results[i];
    }

    vector<vector<int>> teams(n, vector<int>(3));
    set<int> teamMembers;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> teams[i][j];
            teamMembers.insert(teams[i][j]);
        }
    }

    int studentK;
    cin >> studentK;

    vector<int> priorities;
    for (int i = 1; i <= 3 * n; i++) {
        if (teamMembers.find(i) == teamMembers.end() && i != studentK) {
            priorities.push_back(i);
        }
    }

    sort(priorities.begin(), priorities.end(), [&](int a, int b) {
        for (int i = 0; i < n; i++) {
            bool aInTeam = false, bInTeam = false;
            for (int j = 0; j < 3; j++) {
                if (teams[i][j] == a) {
                    aInTeam = true;
                }
                if (teams[i][j] == b) {
                    bInTeam = true;
                }
            }
            if (aInTeam && !bInTeam) return true;
            if (!aInTeam && bInTeam) return false;
        }
        return a < b;
    });

    for (int priority : priorities) {
        cout << priority << " ";
    }
    cout << endl;
    
    return 0;
}