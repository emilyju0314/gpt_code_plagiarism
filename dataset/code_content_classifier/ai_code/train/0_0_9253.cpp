#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        sort(prices.begin(), prices.end());

        int total = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count < m) {
                total += prices[i];
                count++;
            } else {
                count = 0;
            }
        }

        cout << total << endl;
    }

    return 0;
}