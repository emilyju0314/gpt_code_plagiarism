#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<pair<int, int>> operations;

    for (int i = 0; i < n; i++) {
        if (coins[i] != (i + 1)) {
            int idx = i;
            while (coins[idx] != (i + 1)) {
                idx++;
            }

            while (idx > i) {
                operations.push_back({idx, idx + 1});
                swap(coins[idx], coins[idx - 1]);
                idx--;
            }
        }
    }

    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}