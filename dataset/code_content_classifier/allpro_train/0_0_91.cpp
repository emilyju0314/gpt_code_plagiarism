#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long totalDamage = 0;
    int counter = 0;
    vector<pair<int, int>> cards;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int c, d;
            cin >> c >> d;
            cards.push_back({c, d});
        }

        sort(cards.begin(), cards.end());

        long long turnDamage = 0;
        for (int j = 0; j < k; j++) {
            if (counter % 10 == 9) {
                turnDamage += 2 * cards[j].second;
            } else {
                turnDamage += cards[j].second;
            }
            counter++;
        }

        totalDamage += turnDamage;

        cards.clear();
    }

    cout << totalDamage << endl;

    return 0;
}