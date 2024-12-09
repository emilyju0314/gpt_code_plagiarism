#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int pointsBefore;
    int pointsDuring;
};

bool compareTeams(const Team& a, const Team& b) {
    return a.pointsBefore > b.pointsBefore;
}

int main() {
    int n;
    cin >> n;

    vector<Team> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i].pointsBefore >> teams[i].pointsDuring;
    }

    sort(teams.begin(), teams.end(), compareTeams);

    int applauseDuration = 0;
    for (int i = 0; i < n; i++) {
        int currentPlace = i + 1;
        int newPlace = i + 1;

        for (int j = i; j < n; j++) {
            if (teams[j].pointsBefore + teams[j].pointsDuring > teams[i].pointsBefore) {
                newPlace++;
            }
        }

        applauseDuration += abs(currentPlace - newPlace);
    }

    cout << applauseDuration << endl;

    return 0;
}