#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> flavors(n);
        for (int i = 0; i < n; i++) {
            cin >> flavors[i];
        }

        int minimum_coins = 0;
        int coins_of_1 = 0, coins_of_2 = 0, coins_of_3 = 0;
        for (int i = 0; i < n; i++) {
            if (flavors[i] % 3 == 0) {
                coins_of_3 = max(coins_of_3, flavors[i] / 3);
            } else if (flavors[i] % 2 == 0) {
                coins_of_2 = max(coins_of_2, flavors[i] / 2);
            } else {
                coins_of_1 = max(coins_of_1, flavors[i]);
            }
        }

        minimum_coins = coins_of_3 + coins_of_2 + coins_of_1;

        cout << minimum_coins << endl;
    }

    return 0;
}