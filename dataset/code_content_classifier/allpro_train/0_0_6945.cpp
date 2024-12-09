#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Check if the number of windows is valid
        if (n < 3 || n == 4 || n == 6) {
            cout << -1 << endl;
        } else {
            // Try to allocate windows to three-room apartments first
            int rooms3 = n / 3;
            n %= 3;

            // If there are leftovers, allocate them to five-room apartments
            int rooms5 = 0;
            if (n % 5 == 0) {
                rooms5 = n / 5;
            } else {
                rooms3 -= 1;
                n += 3;
                rooms5 = n / 5;
            }

            // Calculate seven-room apartments
            int rooms7 = n - rooms3 * 3 - rooms5 * 5;

            cout << rooms3 << " " << rooms5 << " " << rooms7 << endl;
        }
    }

    return 0;
}