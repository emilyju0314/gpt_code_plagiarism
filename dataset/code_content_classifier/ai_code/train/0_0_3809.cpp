#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> player1_deck(n);
    vector<int> player2_deck(m);

    for (int i = 0; i < n; i++) {
        cin >> player1_deck[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> player2_deck[i];
    }

    sort(player1_deck.rbegin(), player1_deck.rend());
    sort(player2_deck.rbegin(), player2_deck.rend());

    int player1_score = 0;
    int player2_score = 0;
    bool player1_turn = true;

    while (!player1_deck.empty() || !player2_deck.empty()) {
        if (player1_turn && !player1_deck.empty()) {
            int card = player1_deck.back();
            player1_deck.pop_back();
            if (card != -1) {
                player1_score += card;
            } else {
                break; // Jamming card encountered, game ends
            }
            player1_turn = false;
        } else if (!player1_turn && !player2_deck.empty()) {
            int card = player2_deck.back();
            player2_deck.pop_back();
            if (card != -1) {
                player2_score += card;
            } else {
                break; // Jamming card encountered, game ends
            }
            player1_turn = true;
        }
    }

    cout << player1_score - player2_score << endl;

    return 0;
}