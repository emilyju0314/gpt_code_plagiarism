#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    int pockets = 1;
    int current_coin = coins[0];
    int current_count = 1;

    for (int i = 1; i < n; i++) {
        if (coins[i] == current_coin) {
            current_count++;
        } else {
            pockets = max(pockets, current_count);
            current_coin = coins[i];
            current_count = 1;
        }
    }

    pockets = max(pockets, current_count);

    cout << pockets << endl;

    return 0;
}