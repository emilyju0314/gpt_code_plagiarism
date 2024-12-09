#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> coins(5);
    for(int i = 0; i < 5; i++) {
        cin >> coins[i];
    }

    int total_coins = 0;
    for(int coin : coins) {
        total_coins += coin;
    }

    if(total_coins % 5 == 0 && total_coins > 0) {
        int initial_bet = total_coins / 5;
        cout << initial_bet << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}