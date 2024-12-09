#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    vector<int> orders(n+1, 0);
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int day, num_orders;
            cin >> day >> num_orders;
            orders[day] += num_orders;
        } else {
            int p;
            cin >> p;
            int max_orders = 0;
            for(int j = 1; j <= n; j++) {
                if(j >= p && j <= p+k) {
                    max_orders += min(a, orders[j]);
                } else {
                    max_orders += min(b, orders[j]);
                }
            }
            cout << max_orders << endl;
        }
    }

    return 0;
}