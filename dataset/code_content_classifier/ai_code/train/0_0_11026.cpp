#include <iostream>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    bool canDefeat = true;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (s > x) {
            s += y;
        } else {
            canDefeat = false;
            break;
        }
    }

    if (canDefeat) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}