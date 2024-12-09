#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    bool found = false;
    for (int i = 0; i <= 9; i++) {
        if ((a * 10 + i) % b == 0) {
            a = a * 10 + i;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        cout << a;
        for (int i = 1; i < n; i++) {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}