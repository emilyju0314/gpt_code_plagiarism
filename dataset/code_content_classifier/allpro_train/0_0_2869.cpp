#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> fav_teams(k);
    
    // Read the numbers of favorite teams
    for(int i=0; i<k; i++) {
        cin >> fav_teams[i];
    }

    int max_games = 0;
    int rounds = n; // Total number of rounds in the championship

    // Calculate the maximum possible number of games involving favorite teams
    for(int i=0; i<k; i++) {
        int team = fav_teams[i];
        int team_rounds = 0;

        // Calculate number of games with the chosen team involved
        for(int j=0; j<n; j++) {
            if(team <= pow(2, j)) {
                team_rounds = max(team_rounds, rounds - j);
                break;
            }
        }

        max_games = max(max_games, team_rounds);
    }

    cout << max_games << endl;

    return 0;
}