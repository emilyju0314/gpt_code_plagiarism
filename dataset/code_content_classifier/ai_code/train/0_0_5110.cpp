#include <iostream>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if ((x - y >= d - n && x + y <= 2 * n - d && x >= d && y >= d) || (y - x >= d - n && x + y >= d && x <= n && y <= n - d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}