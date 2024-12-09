#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int guess = 0;
        for (int i = 0; i < n; i++) {
            cout << guess << endl;
            cout.flush();

            int r;
            cin >> r;

            if (r == 1) {
                break;
            }

            int y;
            cin >> y;

            guess ^= y;
        }
    }

    return 0;
}