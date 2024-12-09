#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<char, pair<int, int>>> cards;
    for(int i = 0; i < n; i++) {
        char color;
        int red, blue;
        cin >> color >> red >> blue;
        cards.push_back(make_pair(color, make_pair(red, blue));
    }

    int tokens = 0;
    int turns = 0;
    int redCards = 0, blueCards = 0;

    sort(cards.begin(), cards.end());

    for(int i = 0; i < n; i++) {
        int redRequired = max(cards[i].second.first - redCards, 0);
        int blueRequired = max(cards[i].second.second - blueCards, 0);

        if(cards[i].first == 'R') {
            tokens += redRequired;
            blueCards += blueRequired;
        } else {
            tokens += blueRequired;
            redCards += redRequired;
        }

        turns++;
    }

    cout << turns + max((tokens + 1) / 2, 0) << endl;

    return 0;
}