#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Order {
    char direction;
    int price;
    int volume;
};

bool compareSellOrders(Order a, Order b) {
    return a.price > b.price;
}

bool compareBuyOrders(Order a, Order b) {
    return a.price < b.price;
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<Order> sellOrders;
    vector<Order> buyOrders;

    for (int i = 0; i < n; i++) {
        Order order;
        cin >> order.direction >> order.price >> order.volume;
        if (order.direction == 'S') {
            sellOrders.push_back(order);
        } else {
            buyOrders.push_back(order);
        }
    }

    sort(sellOrders.begin(), sellOrders.end(), compareSellOrders);
    sort(buyOrders.begin(), buyOrders.end(), compareBuyOrders);

    for (int i = 0; i < min(s, (int)sellOrders.size()); i++) {
        int volume = 0;
        int j = i;
        while (j < sellOrders.size() && sellOrders[i].price == sellOrders[j].price) {
            volume += sellOrders[j].volume;
            j++;
        }
        cout << "S " << sellOrders[i].price << " " << volume << endl;
        i = j - 1;
    }

    for (int i = 0; i < min(s, (int)buyOrders.size()); i++) {
        int volume = 0;
        int j = i;
        while (j < buyOrders.size() && buyOrders[i].price == buyOrders[j].price) {
            volume += buyOrders[j].volume;
            j++;
        }
        cout << "B " << buyOrders[i].price << " " << volume << endl;
        i = j - 1;
    }

    return 0;
}