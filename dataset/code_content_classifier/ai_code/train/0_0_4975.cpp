#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), order;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> handshake_count(n, 0);
    for (int i = 0; i < n; i++) {
        handshake_count[a[i]]++;
    }

    vector<int> available_order;
    for (int i = 0; i < n; i++) {
        if (handshake_count[i] == 0) {
            available_order.push_back(i);
        }
    }

    int index = 0;
    while (!available_order.empty()) {
        order.push_back(available_order[index]);
        for (int i = index + 1; i < available_order.size(); i++) {
            handshake_count[a[available_order[i]]]--;
            if (handshake_count[a[available_order[i]]] == 0) {
                available_order.push_back(a[available_order[i]]);
            }
        }
        index++;
        available_order.erase(available_order.begin(), available_order.begin() + index);
    }

    if (order.size() == n) {
        cout << "Possible" << endl;
        for (int student : order) {
            cout << student + 1 << " ";
        }
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}