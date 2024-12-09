#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0) break;

        vector<bool> players(m, true);

        int currentPlayer = 0;
        for (int i = 1; i <= n; i++) {
            string statement;
            cin >> statement;

            if (players[currentPlayer]) {
                if (i % 3 == 0 && i % 5 == 0) {
                    if (statement == "FizzBuzz") {
                        currentPlayer = (currentPlayer + 1) % m;
                    } else {
                        players[currentPlayer] = false;
                    }
                } else if (i % 3 == 0) {
                    if (statement == "Fizz") {
                        currentPlayer = (currentPlayer + 1) % m;
                    } else {
                        players[currentPlayer] = false;
                    }
                } else if (i % 5 == 0) {
                    if (statement == "Buzz") {
                        currentPlayer = (currentPlayer + 1) % m;
                    } else {
                        players[currentPlayer] = false;
                    }
                } else {
                    if (statement != to_string(i)) {
                        players[currentPlayer] = false;
                    } else {
                        currentPlayer = (currentPlayer + 1) % m;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (players[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}