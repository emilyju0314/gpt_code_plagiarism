#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<pair<int, int>> offers;
    for (int i = 0; i < m; i++) {
        int d, t;
        cin >> d >> t;
        offers.push_back(make_pair(d, t));
    }

    sort(offers.begin(), offers.end());

    int day = 1;
    int totalMicrotransactions = accumulate(k.begin(), k.end(), 0);
    int microtransactionsOrdered = 0;

    while (microtransactionsOrdered < totalMicrotransactions) {
        for (pair<int, int> offer : offers) {
            if (offer.first == day) {
                int microtransactionsToOrder = min(k[offer.second - 1], totalMicrotransactions - microtransactionsOrdered);
                k[offer.second - 1] -= microtransactionsToOrder;
                microtransactionsOrdered += microtransactionsToOrder;
            }
        }

        day++;
    }

    cout << day - 1 << endl;

    return 0;
}