#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> submissions(n, vector<int>(5));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> submissions[i][j];
        }
    }

    int vasyaScore = 0, petyaScore = 0;

    for(int j = 0; j < 5; j++) {
        if(submissions[0][j] == -1 || submissions[1][j] == -1) {
            continue;
        }
        double ratio = 0.0;

        for(int i = 0; i < n; i++) {
            if(submissions[i][j] != -1) {
                ratio += 1.0;
            }
        }

        double maxPointValue = 2500.0 * (1.0 - (ratio / n));
        
        if(submissions[0][j] < submissions[1][j]) {
            vasyaScore += maxPointValue * (1.0 - (submissions[0][j] / 250.0));
            petyaScore += maxPointValue * (1.0 - (submissions[1][j] / 250.0));
        } else {
            petyaScore += maxPointValue * (1.0 - (submissions[1][j] / 250.0));
            vasyaScore += maxPointValue * (1.0 - (submissions[0][j] / 250.0));
        }
    }

    if(vasyaScore > petyaScore) {
        cout << 0 << endl;
        return 0;
    }

    int numAccounts = 0;

    for(int i = 0; i < 120; i++) {
        bool canBeatPetya = true;

        for(int j = 0; j < 5; j++) {
            if(submissions[0][j] == -1 || submissions[1][j] == -1) {
                continue;
            }
            double ratio = 0.0;

            for(int k = 0; k < n; k++) {
                if(submissions[k][j] != -1) {
                    ratio += 1.0;
                }
            }

            double maxPointValue = 2500.0 * (1.0 - (ratio / n));
        
            if((submissions[0][j] < submissions[1][j] && submissions[0][j] < i) || (submissions[0][j] > submissions[1][j] && submissions[0][j] < i)) {
                vasyaScore += maxPointValue * (1.0 - (submissions[0][j] / 250.0));
            } else {
                canBeatPetya = false;
                break;
            }
        }

        if(canBeatPetya && vasyaScore > petyaScore) {
            cout << i << endl;
            return 0;
        }

        numAccounts++;
    }

    cout << -1 << endl;

    return 0;
}