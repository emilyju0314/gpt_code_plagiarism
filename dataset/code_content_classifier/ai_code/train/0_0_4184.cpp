#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int buyPrice;
    int sellPrice;
    int remaining;
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
        planets[i].items.resize(m);
        for(int j = 0; j < m; j++) {
            cin >> planets[i].items[j].buyPrice >> planets[i].items[j].sellPrice >> planets[i].items[j].remaining;
        }
    }

    int maxProfit = 0;

    for(int start = 0; start < n; start++) {
        for(int end = 0; end < n; end++) {
            if(start == end) continue;

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < m; j++) {
                    int itemsBought = min(planets[start].items[i].remaining, k / planets[start].items[i].buyPrice);
                    int moneyNeeded = itemsBought * planets[start].items[i].buyPrice;

                    int itemsSold = min(itemsBought, planets[end].items[j].remaining);
                    int profit = itemsSold * planets[end].items[j].sellPrice - moneyNeeded;
                    
                    maxProfit = max(maxProfit, profit);
                }
            }
        }
    }

    cout << maxProfit << endl;

    return 0;
}