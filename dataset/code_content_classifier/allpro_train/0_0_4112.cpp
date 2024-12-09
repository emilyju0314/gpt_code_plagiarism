#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> player1, player2;
    int k1, k2;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int card;
        cin >> card;
        player1.push_back(card);
    }

    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int card;
        cin >> card;
        player2.push_back(card);
    }

    int fights = 0;
    set<pair<vector<int>, vector<int>>> seen;

    while (!player1.empty() && !player2.empty()) {
        if (seen.count({player1, player2})) {
            cout << -1 << endl;
            return 0;
        }

        seen.insert({player1, player2});

        int card1 = player1.front();
        int card2 = player2.front();
        
        player1.erase(player1.begin());
        player2.erase(player2.begin());

        if (card1 > card2) {
            player1.push_back(card2);
            player1.push_back(card1);
        } else {
            player2.push_back(card1);
            player2.push_back(card2);
        }

        fights++;
    }

    if (player2.empty()) {
        cout << fights << " 1" << endl;
    } else {
        cout << fights << " 2" << endl;
    }

    return 0;
}