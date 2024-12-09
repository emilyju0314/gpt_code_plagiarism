#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;

        bool possible = true;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != c[i] && b[i] != c[i]) {
                possible = false;
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