#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> sets(n);
    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        sets[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            cin >> sets[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int min_price = INT_MAX;

    for (int k = 1; k <= n; k++) {
        vector<bool> distinct(n + 1, false);
        int price = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int num : sets[i]) {
                if (!distinct[num]) {
                    distinct[num] = true;
                    count++;
                }
            }
            price += prices[i];
        }

        if (count >= k) {
            min_price = min(min_price, price);
        }
    }

    cout << (min_price == INT_MAX ? 0 : min_price) << endl;

    return 0;
}