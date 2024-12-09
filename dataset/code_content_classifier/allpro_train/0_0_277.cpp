#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
    int price, type, index;
};

bool compareItems(item a, item b) {
    return a.price < b.price;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<item> stools, pencils;
    vector<vector<item>> carts(k);

    for (int i = 0; i < n; i++) {
        int price, type;
        cin >> price >> type;
        if (type == 1) {
            stools.push_back({price, type, i + 1});
        } else {
            pencils.push_back({price, type, i + 1});
        }
    }

    sort(stools.begin(), stools.end(), compareItems);
    sort(pencils.begin(), pencils.end(), compareItems);

    int cartIdx = 0;
    for (int i = 0; i < stools.size(); i++) {
        carts[cartIdx].push_back(stools[i]);
        cartIdx = (cartIdx + 1) % k;
    }

    for (int i = 0; i < pencils.size(); i++) {
        carts[cartIdx].push_back(pencils[i]);
        cartIdx = (cartIdx + 1) % k;
    }

    double total = 0.0;
    for (auto cart : carts) {
        int minPriceIdx = 0;
        for (int i = 1; i < cart.size(); i++) {
            if (cart[i].price < cart[minPriceIdx].price) {
                minPriceIdx = i;
            }
        }
        for (int i = 0; i < cart.size(); i++) {
            if (i == minPriceIdx) {
                total += 0.5 * cart[i].price;
            } else {
                total += cart[i].price;
            }
        }
    }

    cout << fixed << setprecision(1) << total << endl;
    for (auto cart : carts) {
        cout << cart.size() << " ";
        for (auto item : cart) {
            cout << item.index << " ";
        }
        cout << endl;
    }

    return 0;
}