#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int max_profit = 0;
    for (int i = 0; i < n - 1; i++) {
        int profit = max(0, prices[i] - prices[i + 1] - c);
        max_profit = max(max_profit, profit);
    }

    cout << max_profit << endl;

    return 0;
}