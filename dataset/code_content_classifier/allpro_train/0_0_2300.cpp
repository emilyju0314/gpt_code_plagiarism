#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    // Initialize a vector to store the number of orders for each day
    vector<int> orders(n+1, 0);

    while (q--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int di, ai;
            cin >> di >> ai;
            orders[di] += ai;
        } else {
            int pi;
            cin >> pi;

            int total_orders = 0;
            int thimbles = 0;

            for (int i = 1; i <= n; i++) {
                thimbles += a;
                if (i >= pi && i <= pi + k - 1) {
                    thimbles -= b;
                }

                total_orders += min(thimbles, orders[i]);
            }

            cout << total_orders << endl;
        }
    }

    return 0;
}