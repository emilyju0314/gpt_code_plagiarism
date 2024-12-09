#include <iostream>
#include <vector>

using namespace std;

int main() {
    int P, N1, N5, N10, N50, N100, N500;

    while (true) {
        cin >> P >> N1 >> N5 >> N10 >> N50 >> N100 >> N500;

        if (P == 0) {
            break;
        }

        int total_coins = 0;
        vector<int> coins = {1, 5, 10, 50, 100, 500};

        int change = N500*500 + N100*100 + N50*50 + N10*10 + N5*5 + N1 - P;

        for (int i = coins.size() - 1; i >= 0; i--) {
            int num_coins = change / coins[i];
            total_coins += num_coins;
            change -= num_coins * coins[i];
        }

        cout << total_coins << endl;
    }

    return 0;
}