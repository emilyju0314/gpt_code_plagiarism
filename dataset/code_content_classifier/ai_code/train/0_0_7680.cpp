#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Initialize a grid to represent the city
    char city[4][n];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            city[i][j] = '.';
        }
    }

    // Check if it is possible to place the hotels
    if (k <= (n - 2) / 2) {
        cout << "YES" << endl;

        // Place hotels in the city
        for (int i = 1; i <= k; i++) {
            city[1][2 * i] = '#';
            city[2][2 * i] = '#';
        }

        // Print the city
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                cout << city[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}