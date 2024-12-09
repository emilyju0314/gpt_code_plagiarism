#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d, l;
    cin >> n >> d >> l;

    vector<int> cards(n);

    // Iterating through all possible combinations of cards
    for (int i = 1; i <= l; i++) {
        cards[0] = i;
        for (int j = 1; j <= l; j++) {
            cards[1] = j;
            bool valid = true;
            int diff = cards[0] - cards[1];
            for (int k = 2; k < n; k++) {
                cards[k] = diff;
                if (cards[k] <= 0 || cards[k] > l) {
                    valid = false;
                    break;
                }
                diff = cards[k-1] - cards[k];
            }
            if (valid && diff == d) {
                for (int k = 0; k < n; k++) {
                    cout << cards[k] << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}