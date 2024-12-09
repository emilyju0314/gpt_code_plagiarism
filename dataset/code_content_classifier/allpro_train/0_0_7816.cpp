#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }

        long long total_changes = 0;
        for (int i = 1; i < n; i++) {
            int target_price = (long long)prices[i - 1] * k / 100;
            if (prices[i] <= target_price) {
                continue;
            }
            total_changes += prices[i] - target_price;
            prices[i] = target_price;
        }

        cout << total_changes << endl;
    }

    return 0;
}