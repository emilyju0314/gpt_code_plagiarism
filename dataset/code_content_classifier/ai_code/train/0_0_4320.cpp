#include <iostream>
#include <vector>

using namespace std;

void shuffle(vector<int>& cards, int x, int y, int n) {
    vector<int> pileA(cards.begin(), cards.begin() + x);
    vector<int> pileB(cards.begin() + x, cards.begin() + y);
    vector<int> pileC(cards.begin() + y, cards.end());

    for (int i = 0; i < y - x; i++) {
        cards[i] = pileB[i];
    }
    for (int i = 0; i < x; i++) {
        cards[y - x + i] = pileA[i];
    }
    for (int i = 0; i < n - y; i++) {
        cards[y + i] = pileC[i];
    }
}

int countCards(vector<int>& cards, int p, int q, int r) {
    int count = 0;
    for (int i = p - 1; i < q; i++) {
        if (cards[i] <= r) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int m, p, q, r;
        cin >> m >> p >> q >> r;

        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cards[i] = i + 1;
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            shuffle(cards, x, y, n);
        }

        cout << countCards(cards, p, q, r) << endl;
    }

    return 0;
}