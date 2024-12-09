#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());
    
    int most_cards = 0;
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (cards[i] == cards[i-1]) {
            count++;
        } else {
            most_cards = max(most_cards, count);
            count = 1;
        }
    }
    most_cards = max(most_cards, count);

    int remaining_cards = N - most_cards;
    
    if (remaining_cards % 2 == 0) {
        cout << remaining_cards - 1 << endl;
    } else {
        cout << remaining_cards << endl;
    }

    return 0;
}