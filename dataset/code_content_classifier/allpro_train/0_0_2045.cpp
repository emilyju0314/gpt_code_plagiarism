#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    if (prices[0] == prices[n - 1]) {
        cout << "0" << endl;
    } else {
        if (k == 1) {
            cout << "-1" << endl;
        } else {
            long long total_time = 0;
            for (int i = 1; i < n; i++) {
                total_time += (prices[i] - prices[0]) / k;
            }
            cout << total_time << endl;
        }
    }

    return 0;
}