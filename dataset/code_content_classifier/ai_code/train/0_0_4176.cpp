#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int xr = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            xr ^= a[i]; // Calculating xor of all elements in the array
        }

        // If xor of all elements is 0, then it's a draw
        if (xr == 0) {
            cout << "DRAW" << endl;
        } else {
            // Count the number of elements in the array that have xor less than the all elements xor
            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] ^ xr) < a[i]) {
                    count++;
                }
            }

            // If the count is 0 or even, Koa will lose, otherwise Koa wins
            if (count == 0 || count % 2 == 0) {
                cout << "LOSE" << endl;
            } else {
                cout << "WIN" << endl;
            }
        }
    }

    return 0;
}