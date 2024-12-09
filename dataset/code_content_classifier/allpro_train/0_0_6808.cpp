#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> positions(n);
    for(int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    vector<int> order_hardness(n+1);

    vector<bool> coins(n+1, false);
    int max_diff = 0;

    for(int i = 0; i < n; i++) {
        coins[positions[i]] = true;

        int prev_x = 0;
        int prev_o = 0;
        int x = 0;
        int o = 0;

        for(int j = 1; j <= n; j++) {
            if(coins[j]) {
                x++;
                if(prev_o > 0) {
                    order_hardness[i+1]++;
                }
                prev_x = x;
            } else {
                o++;
                if(prev_x > 0) {
                    order_hardness[i+1]++;
                }
                prev_o = o;
            }
        }

        max_diff = max(max_diff, order_hardness[i+1]);
    }

    order_hardness[0] = 1;
    for(int i = 1; i < n; i++) {
        order_hardness[i] = max(order_hardness[i], order_hardness[i-1] - 1);
    }

    order_hardness[n] = max_diff;

    for(int i = 0; i <= n; i++) {
        cout << order_hardness[i] << " ";
    }

    return 0;
}