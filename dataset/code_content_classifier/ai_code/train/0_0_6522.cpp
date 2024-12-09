#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, totalCoins = 0;
    cin >> n;

    vector<int> chests(n);
    for (int i = 0; i < n; i++) {
        cin >> chests[i];
        totalCoins += chests[i];
    }

    int moves = 0;
    bool possible = false;
    for (int x = 1; 2*x + 1 <= n && !possible; x++) {
        int totalCoinsTaken = 0;
        for (int i = x; i < n && 2*x + 1 <= n; i += 2*x + 1) {
            totalCoinsTaken += chests[i];
        }
        
        if (totalCoinsTaken == totalCoins) {
            possible = true;
            moves = (n - 1) / (2*x + 1) + 1;
        }
    }

    if (possible) {
        cout << moves << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}