#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n, k;
        cin >> n >> k;

        if (n == 0 && k == 0) {
            break;
        }

        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }

        vector<int> sortedCards = cards;
        sort(sortedCards.begin(), sortedCards.end());

        int Ck = 1;
        for (int i = 0; i < k; i++) {
            Ck *= sortedCards[n - i - 1];
        }

        int maxGrade = 0;
        do {
            int Ck_prime = 1;
            for (int i = 0; i < k; i++) {
                Ck_prime *= cards[n - i - 1];
            }
            if (Ck_prime - Ck > maxGrade) {
                maxGrade = Ck_prime - Ck;
            }
        } while (next_permutation(cards.begin(), cards.end()));

        if (maxGrade > 0) {
            cout << maxGrade << endl;
        } else {
            cout << "NO GAME" << endl;
        }
    }

    return 0;
}