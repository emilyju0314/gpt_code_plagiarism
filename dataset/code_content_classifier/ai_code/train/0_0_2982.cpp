#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string home, away;
    cin >> home >> away;
    int n;
    cin >> n;

    vector<string> names = {home, away};
    map<int, map<int, int>> red_cards; // minute -> team -> player

    for (int i = 0; i < n; i++) {
        int minute, player;
        char team, card;
        cin >> minute >> team >> player >> card;

        if (card == 'r') {
            red_cards[minute][team - 'a'][player] = 1;
        } else {
            red_cards[minute][team - 'a'][player] = 0;
        }
    }

    for (auto it = red_cards.begin(); it != red_cards.end(); it++) {
        for (int i = 0; i < names.size(); i++) {
            for (auto player : it->second[i]) {
                if (player.second == 1) {
                    cout << names[i] << " " << player.first << " " << it->first << endl;
                }
            }
        }
    }

    return 0;
}