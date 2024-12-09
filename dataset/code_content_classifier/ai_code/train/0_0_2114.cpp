#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> ci(n);
    for (int i = 0; i < n; i++) {
        cin >> ci[i];
    }

    int max_price = 0;
    sort(ci.begin(), ci.end());

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int total_price = 0;
            int days = 0;
            for (int k = i; k <= j; k++) {
                total_price += ci[k];
                days++;
            }
            if (total_price <= d * days) {
                max_price = max(max_price, total_price);
            }
        }
    }

    cout << max_price << " " << n << endl;

    return 0;
}