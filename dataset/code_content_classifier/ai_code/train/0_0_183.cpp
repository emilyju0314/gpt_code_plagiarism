#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int prevPlays = 0, prevClears = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            int p, c;
            cin >> p >> c;

            if (p < prevPlays || c < prevClears || p - prevPlays < c - prevClears) {
                possible = false;
            }

            prevPlays = p;
            prevClears = c;
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}