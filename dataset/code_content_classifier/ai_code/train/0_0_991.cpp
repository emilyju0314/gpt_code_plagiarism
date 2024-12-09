#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0) {
        cout << -1 << endl;
    } else if (m > 2 * n + 2 || n > m + 1) {
        cout << -1 << endl;
    } else {
        while (n > 0 || m > 0) {
            if (m > n && m > 0) {
                cout << 1;
                m--;
            } else if (n > 0) {
                cout << 0;
                n--;
                if (m > n) {
                    cout << 1;
                    m--;
                }
            }
        }
    }

    return 0;
}