#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int l, r, m;
        cin >> l >> r >> m;

        for (int a = l; a <= r; a++) {
            for (int b = l; b <= r; b++) {
                for (int c = l; c <= r; c++) {
                    if (a * (m/a) + b - c == m) {
                        cout << a << " " << b << " " << c << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}