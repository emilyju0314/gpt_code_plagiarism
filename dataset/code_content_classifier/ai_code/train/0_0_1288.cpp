#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    unordered_map<string, int> blueCards;
    for (int i = 0; i < N; i++) {
        string card;
        cin >> card;
        blueCards[card]++;
    }

    cin >> M;

    int maxProfit = 0;
    for (int i = 0; i < M; i++) {
        string card;
        cin >> card;
        if (blueCards.find(card) != blueCards.end()) {
            maxProfit++;
        }
    }

    cout << maxProfit << endl;

    return 0;
}