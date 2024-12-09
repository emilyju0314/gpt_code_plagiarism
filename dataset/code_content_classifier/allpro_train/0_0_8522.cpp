#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> auctionQuestions(m);
    for (int i = 0; i < m; i++) {
        cin >> auctionQuestions[i];
    }

    sort(auctionQuestions.begin(), auctionQuestions.end());

    long long points = 0;
    for (int i = 0; i < m; i++) {
        if (points < prices[auctionQuestions[i] - 1]) {
            points += prices[auctionQuestions[i] - 1];
        } else {
            points += points;
        }
    }

    cout << points << endl;

    return 0;
}