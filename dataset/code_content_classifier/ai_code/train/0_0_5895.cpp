#include <iostream>

using namespace std;

int main() {
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    while (true) {
        if (a == b) {
            cout << "YES" << endl;
            return 0;
        }
        if (a == x || b == y) {
            break;
        }
        a++;
        b--;
        if (a > n) {
            a = 1;
        }
        if (b < 1) {
            b = n;
        }
    }

    cout << "NO" << endl;

    return 0;
}