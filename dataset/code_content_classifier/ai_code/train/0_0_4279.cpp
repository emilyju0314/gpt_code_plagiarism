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

    sort(prices.begin(), prices.end());

    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (prices[i] < 0) {
            sum -= prices[i];
        }
    }

    cout << sum << endl;

    return 0;
}