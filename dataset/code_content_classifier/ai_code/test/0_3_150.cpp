#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long int total_coins = 0;
        int min_cost = 1000000000; // Initialize to a large value

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            min_cost = min(min_cost, a);
        }

        total_coins = min_cost / 3;

        for (int i = 0; i < min_cost % 3; i++) {
            if (i == 2) total_coins++;
            if (i == 1) total_coins += 2;
        }

        cout << total_coins << endl;
    }

    return 0;
}