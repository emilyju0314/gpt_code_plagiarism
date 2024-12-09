#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chips(n);
    for(int i = 0; i < n; i++) {
        cin >> chips[i];
    }

    int minCoins = INT_MAX;
    for(int target = 1; target <= 100; target++) {
        int coins = 0;
        for(int i = 0; i < n; i++) {
            int diff = abs(chips[i] - target);
            coins += (diff % 2);
        }
        minCoins = min(minCoins, coins);
    }

    cout << minCoins << endl;

    return 0;
}