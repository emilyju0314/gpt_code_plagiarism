#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cards(n);
    for(int i = 0; i < n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        cards[i] = make_pair(ai, bi);
    }

    sort(cards.begin(), cards.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    });

    int points = 0;
    int counter = 1;
    for(int i = 0; i < n; i++) {
        points += cards[i].first;
        counter += cards[i].second - 1;
        counter = max(counter, 0);
    }

    cout << points << endl;

    return 0;
}