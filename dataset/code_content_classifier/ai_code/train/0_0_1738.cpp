#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int ang;
        cin >> ang;

        int gcd = __gcd(180, ang);
        int n = 180 / gcd;

        if (n >= 3) {
            cout << n << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}