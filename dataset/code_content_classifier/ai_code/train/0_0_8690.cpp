#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Order {
    int a, b, index;
};

bool compareOrders(const Order& o1, const Order& o2) {
    if (o1.a != o2.a) {
        return o1.a > o2.a;
    } else {
        return o1.b < o2.b;
    }
}

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<Order> orders(n);
    for (int i = 0; i < n; i++) {
        cin >> orders[i].a >> orders[i].b;
        orders[i].index = i + 1;
    }

    sort(orders.begin(), orders.end(), compareOrders);

    long long totalGreyHairs = 0;
    vector<int> resultIndices;
    for (int i = 0; i < p; i++) {
        totalGreyHairs += orders[i].a;
        resultIndices.push_back(orders[i].index);
    }

    sort(resultIndices.begin(), resultIndices.end());
    cout << totalGreyHairs << endl;
    for (int i = 0; i < p; i++) {
        cout << resultIndices[i] << " ";
    }
    cout << endl;

    return 0;
}