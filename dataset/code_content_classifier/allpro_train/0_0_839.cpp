#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(k*n);
    for (int i = 0; i < k*n; i++) {
        cin >> cards[i];
    }

    vector<int> favorite(n);
    for (int i = 0; i < n; i++) {
        cin >> favorite[i];
    }

    vector<int> joyLevels(k);
    for (int i = 0; i < k; i++) {
        cin >> joyLevels[i];
    }

    vector<int> freq(100001, 0);
    for (int i = 0; i < k*n; i++) {
        freq[cards[i]]++;
    }

    int totalJoy = 0;
    for (int i = 0; i < n; i++) {
        vector<int> playerCards;
        for (int j = 0; j < k*n; j++) {
            if (cards[j] == favorite[i]) {
                playerCards.push_back(cards[j]);
            }
        }
        sort(playerCards.begin(), playerCards.end(), greater<int>());
        int joy = 0;
        for (int j = 0; j < min(k, (int)playerCards.size()); j++) {
            joy += joyLevels[j];
        }
        totalJoy += joy;
    }

    cout << totalJoy << endl;

    return 0;
}