#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int points;
};

bool comparePlayers(Player& p1, Player& p2) {
    return p1.points > p2.points;
}

int main() {
    int n;
    cin >> n;

    vector<Player> players(n);
    map<string, string> categories;

    for (int i = 0; i < n; i++) {
        cin >> players[i].name >> players[i].points;
    }

    sort(players.begin(), players.end(), comparePlayers);

    int m = 0;
    for (int i = 0; i < n; i++) {
        int betterPlayers = i;
        int totalPlayers = n;

        while(i+1 < n && players[i+1].points == players[i].points) {
            i++;
            totalPlayers++;
        }

        double percentile = (double) (betterPlayers + 1) / totalPlayers * 100;

        if (percentile > 50) {
            categories[players[i].name] = "noob";
        } else if (percentile > 20) {
            categories[players[i].name] = "random";
        } else if (percentile > 10) {
            categories[players[i].name] = "average";
        } else if (percentile > 1) {
            categories[players[i].name] = "hardcore";
        } else {
            categories[players[i].name] = "pro";
        }

        m++;
    }

    cout << m << endl;
    for (auto it = categories.begin(); it != categories.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}