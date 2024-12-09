#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        bool possible = false;
        for (int i = 0; i <= x / 11; i++) {
            if ((x - 11 * i) % 111 == 0) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}