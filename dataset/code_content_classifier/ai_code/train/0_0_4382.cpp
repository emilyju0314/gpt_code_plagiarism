#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom struct to hold expiry date and index of the carton
struct Carton {
    int expiry_date;
    int index;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Carton> fridge(n);
    for (int i = 0; i < n; i++) {
        cin >> fridge[i].expiry_date;
        fridge[i].index = i + 1; // Carton index starts from 1
    }

    vector<Carton> shop(m);
    for (int i = 0; i < m; i++) {
        cin >> shop[i].expiry_date;
        shop[i].index = i + n + 1; // Carton index starts from n+1
    }

    sort(fridge.begin(), fridge.end(), [](Carton a, Carton b) {
        return a.expiry_date < b.expiry_date;
    });

    sort(shop.begin(), shop.end(), [](Carton a, Carton b) {
        return a.expiry_date < b.expiry_date;
    });

    int fridge_idx = 0, shop_idx = 0;
    vector<int> cartons_to_buy;

    for (int i = 0; i < k; i++) {
        if (fridge_idx < n && (fridge[fridge_idx].expiry_date <= i || i == k-1)) {
            fridge_idx++;
        } else if (shop_idx < m) {
            cartons_to_buy.push_back(shop[shop_idx].index);
            shop_idx++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cartons_to_buy.size() << endl;
    for (int carton_index : cartons_to_buy) {
        cout << carton_index << " ";
    }

    return 0;
}