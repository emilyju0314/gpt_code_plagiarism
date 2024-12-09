#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }

        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            int score = 0;
            for (int j = 0; j < n - 1; j++) {
                int sum = cards[j] + cards[(j + 1) % n];
                score = max(score, sum);
            }
            maxScore += score;
            rotate(cards.begin(), cards.begin() + 1, cards.end());
        }

        cout << maxScore << endl;
    }

    return 0;
}