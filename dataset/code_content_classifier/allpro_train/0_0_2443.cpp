#include <iostream>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << 0 << endl;
    } else {
        cout << "1000 ";
        for (int i = 1; i < r; i++) {
            cout << 999 - i << " ";
        }
        cout << endl;

        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << 1000 + i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}