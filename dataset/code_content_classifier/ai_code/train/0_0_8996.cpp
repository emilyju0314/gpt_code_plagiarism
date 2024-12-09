#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
            break;
        }

        int na, nb, nc;
        cin >> na >> nb >> nc;

        vector<int> prices = { na * a, nb * b, nc * c };

        sort(prices.begin(), prices.end());

        int total_price = 0;
        if (prices[0] + prices[1] + prices[2] >= 3 * e) {
            total_price = d * e;
        } else {
            total_price = prices[0] + prices[1] + prices[2];
        }

        cout << total_price << endl;
    }

    return 0;
}