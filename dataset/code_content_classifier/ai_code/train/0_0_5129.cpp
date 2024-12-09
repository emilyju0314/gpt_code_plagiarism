#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;

        int aliceWins = 0, bobWins = 0;
        int currentPlayer = 0; // 0 for Alice, 1 for Bob

        while (x > 0 && y > 0) {
            if (currentPlayer == 0) {
                x--;
                currentPlayer = 1;
            } else {
                y--;
                currentPlayer = 0;
            }
        }

        aliceWins = y / 2;
        bobWins = x;

        cout << aliceWins << " " << bobWins << endl;
    }

    return 0;
}