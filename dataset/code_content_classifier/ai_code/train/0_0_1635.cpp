#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int d;
    while (cin >> d) {
        if (d == 0) {
            break;
        }

        int n, m;
        cin >> n >> m;

        vector<int> stores(n);
        for (int i = 0; i < n - 1; i++) {
            cin >> stores[i];
        }

        stores[n - 1] = d;

        sort(stores.begin(), stores.end());

        vector<int> deliveries(m);
        for (int i = 0; i < m; i++) {
            cin >> deliveries[i];
        }

        int total_distance = 0;
        for (int i = 0; i < m; i++) {
            auto it = lower_bound(stores.begin(), stores.end(), deliveries[i]);
            int distance_clockwise = *it - deliveries[i];
            int distance_counter_clockwise = d - *it + deliveries[i];

            total_distance += min(distance_clockwise, distance_counter_clockwise);
        }

        cout << total_distance << endl;
    }

    return 0;
}