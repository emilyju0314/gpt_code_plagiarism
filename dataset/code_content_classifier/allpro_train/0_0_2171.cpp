#include <iostream>
#include <stack>
#include <string>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int, bool>> orders; // pair of price and direction (BUY or SELL)
    int bestBuy = 0, bestSell = INT_MAX;
    long long ways = 1;

    for (int i = 0; i < n; i++) {
        string action;
        int price;
        cin >> action >> price;

        if (action == "ADD") {
            if (price >= bestSell) {
                ways = 0;
                break;
            } else if (price <= bestBuy) {
                ways = (ways * 2) % MOD;
            }

            if (price > bestBuy) {
                orders.push({price, true}); // BUY
                bestBuy = price;
            } else {
                orders.push({price, false}); // SELL
                bestSell = price;
            }
        } else {
            bool direction = orders.top().second;
            orders.pop();

            if ((direction && price > bestBuy) || (!direction && price < bestSell)) {
                ways = 0;
                break;
            }

            if (direction) {
                bestSell = price;
            } else {
                bestBuy = price;
            }
        }
    }

    cout << ways << endl;

    return 0;
}