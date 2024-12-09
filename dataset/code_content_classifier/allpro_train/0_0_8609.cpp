#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    vector<int> sellers;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        bool can_make_deal = false;
        for (int j = 0; j < k; j++) {
            int price;
            cin >> price;
            if (price < v) {
                can_make_deal = true;
            }
        }
        if (can_make_deal) {
            sellers.push_back(i + 1);
        }
    }

    cout << sellers.size() << endl;
    for (int i = 0; i < sellers.size(); i++) {
        cout << sellers[i] << " ";
    }

    return 0;
}