#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> friends(n);
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        for (int j = 0; j < f; j++) {
            int fav;
            cin >> fav;
            friends[i].insert(fav);
        }
    }

    vector<pair<int, vector<int>>> pizzas(m);
    for (int i = 0; i < m; i++) {
        int price, r;
        cin >> price >> r;
        vector<int> ingredients(r);
        for (int j = 0; j < r; j++) {
            cin >> ingredients[j];
        }
        pizzas[i] = {price, ingredients};
    }

    int ans1 = -1, ans2 = -1;
    int maxFriends = 0, minPrice = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            set<int> pizzaIngredients;
            pizzaIngredients.insert(pizzas[i].second.begin(), pizzas[i].second.end());
            pizzaIngredients.insert(pizzas[j].second.begin(), pizzas[j].second.end());

            int friendsCount = 0;
            for (const auto& f : friends) {
                bool satisfied = true;
                for (const auto& fav : f) {
                    if (pizzaIngredients.find(fav) == pizzaIngredients.end()) {
                        satisfied = false;
                        break;
                    }
                }
                if (satisfied) {
                    friendsCount++;
                }
            }

            if (friendsCount > maxFriends || (friendsCount == maxFriends && pizzas[i].first + pizzas[j].first < minPrice)) {
                maxFriends = friendsCount;
                minPrice = pizzas[i].first + pizzas[j].first;
                ans1 = i;
                ans2 = j;
            }
        }
    }

    cout << ans1 + 1 << " " << ans2 + 1 << endl;

    return 0;
}