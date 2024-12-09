#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> buy_prices(n);
    for(int i = 0; i < n; i++) {
        cin >> buy_prices[i];
    }

    vector<int> sell_prices(m);
    for(int i = 0; i < m; i++) {
        cin >> sell_prices[i];
    }

    int max_bourles = r;
    int min_buy_price = *min_element(buy_prices.begin(), buy_prices.end());
    int max_sell_price = *max_element(sell_prices.begin(), sell_prices.end());

    if(min_buy_price >= max_sell_price) {
        cout << max_bourles << endl;
    } else {
        int shares_bought = max_bourles / min_buy_price;
        max_bourles -= shares_bought * min_buy_price;
        max_bourles += shares_bought * max_sell_price;

        cout << max_bourles << endl;
    }

    return 0;
}