#include <iostream>
#include <vector>
using namespace std;

struct Team {
    int problemsSolved;
    int penaltyTime;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Team> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i].problemsSolved >> teams[i].penaltyTime;
    }

    int countTeams = 0;
    for (int i = 0; i < n; i++) {
        int betterTeams = 0;
        for (int j = 0; j < n; j++) {
            if (teams[i].problemsSolved < teams[j].problemsSolved ||
                (teams[i].problemsSolved == teams[j].problemsSolved && teams[i].penaltyTime > teams[j].penaltyTime)) {
                betterTeams++;
            }
        }
        if (betterTeams == k-1) {
            countTeams++;
        }
    }

    cout << countTeams << endl;

    return 0;
}