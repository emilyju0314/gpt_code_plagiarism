#include <iostream>
using namespace std;

int main() {
    long long q;
    cin >> q;

    if (q % 2 == 0) {
        cout << 1 << endl;
        cout << q / 2 << endl;
    } else {
        bool found = false;
        for (long long i = 3; i * i <= q; i += 2) {
            if (q % i == 0) {
                found = true;
                cout << 2 << endl;
                cout << i << endl;
                break;
            }
        }

        if (!found) {
            cout << 1 << endl;
            cout << 0 << endl;
        }
    }

    return 0;
}