#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m < n - 1 || m > (n * (n - 1)) / 2) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 2; i <= n; i++) {
            cout << "1 " << i << endl;
            m--;
            if (m == 0) break;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (__gcd(i, j) == 1) {
                    cout << i << " " << j << endl;
                    m--;
                }
                if (m == 0) break;
            }
            if (m == 0) break;
        }
    }

    return 0;
}