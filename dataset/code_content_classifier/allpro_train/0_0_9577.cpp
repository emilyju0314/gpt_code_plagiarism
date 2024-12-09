#include <iostream>

using namespace std;

int main() {
    int n, d, h;
    cin >> n >> d >> h;

    if (d > 2*h || d < h || (h == 1 && d == 1 && n > 2)) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i <= h+1; i++) {
            cout << i-1 << " " << i << endl;
        }
        if (h < d) {
            cout << 1 << " " << h+2 << endl;
            for (int i = h+3; i <= d+2; i++) {
                cout << i-1 << " " << i << endl;
            }
        }
        for (int i = d+3; i <= n; i++) {
            cout << 1 << " " << i << endl;
        }
    }

    return 0;
}