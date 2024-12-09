#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prices_now(n);
    vector<int> prices_after(n);

    for (int i = 0; i < n; i++) {
        cin >> prices_now[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> prices_after[i];
    }

    vector<pair<int, int>> price_diff;
    for (int i = 0; i < n; i++) {
        price_diff.push_back({prices_now[i] - prices_after[i], i});
    }

    sort(price_diff.begin(), price_diff.end());

    int total_money = 0;
    for (int i = 0; i < k; i++) {
        total_money += prices_now[price_diff[i].second];
    }
    for (int i = k; i < n; i++) {
        total_money += prices_after[price_diff[i].second];
    }

    cout << total_money << endl;

    return 0;
}