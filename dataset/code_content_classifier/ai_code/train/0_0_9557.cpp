#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    int buyPrice;
    int sellPrice;
    int quantity;
};

struct Planet {
    string name;
    vector<Item> items;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Planet> planets(n);

    for(int i = 0; i < n; i++) {
        cin >> planets[i].name;
        for(int j = 0; j < m; j++) {
            int aij, bij, cij;
            cin >> aij >> bij >> cij;
            planets[i].items.push_back({aij, bij, cij});
        }
    }

    int maxProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            for(int x = 0; x < planets[i].items.size(); x++) {
                for(int y = 0; y < planets[j].items.size(); y++) {
                    int maxBuyA = min(k / planets[i].items[x].buyPrice, planets[i].items[x].quantity);
                    int maxSellA = min(maxBuyA, planets[j].items[y].quantity);
                    int profit = maxSellA * (planets[j].items[y].sellPrice) - maxBuyA * (planets[i].items[x].buyPrice);

                    maxProfit = max(maxProfit, profit);
                }
            }
        }
    }

    cout << maxProfit << endl;

    return 0;
}