#include <iostream>

using namespace std;

int main() {
    int n, m, S_x, S_y;
    cin >> n >> m >> S_x >> S_y;

    // Print initial cell
    cout << S_x << " " << S_y << endl;

    // Visit all cells except initial cell
    for (int i = 1; i <= m; i++) {
        if (i != S_y) {
            cout << S_x << " " << i << endl;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != S_x) {
            cout << i << " " << m << endl;
        }
    }

    // Visit border cells in reverse order
    for (int i = m - 1; i >= 1; i--) {
        cout << n << " " << i << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        cout << i << " 1" << endl;
    }

    return 0;
}