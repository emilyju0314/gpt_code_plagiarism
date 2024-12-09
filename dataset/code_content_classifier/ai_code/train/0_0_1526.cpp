#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> submissionTimes(n, vector<int>(5));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> submissionTimes[i][j];
        }
    }

    vector<int> solvedByParticipants(5, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            if(submissionTimes[i][j] != -1) {
                solvedByParticipants[j]++;
            }
        }
    }

    vector<int> maxScores(5);
    for(int i = 0; i < 5; i++) {
        maxScores[i] = 1500 * (n/solvedByParticipants[i]);
    }

    vector<int> vasyaScores;
    for(int accounts = 0; accounts <= 120; accounts++) {
        int vasyaScore = 0;
        for(int j = 0; j < 5; j++) {
            if(submissionTimes[0][j] != -1) {
                vasyaScore += max(0, maxScores[j] - maxScores[j] * submissionTimes[0][j] / 250 - 50 * accounts);
            }
        }
        vasyaScores.push_back(vasyaScore);
    }

    int petyaScore = 0;
    for(int j = 0; j < 5; j++) {
        if(submissionTimes[1][j] != -1) {
            petyaScore += maxScores[j] - maxScores[j] * submissionTimes[1][j] / 250;
        }
    }

    for(int accounts = 0; accounts <= 120; accounts++) {
        if(vasyaScores[accounts] > petyaScore) {
            cout << accounts << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}