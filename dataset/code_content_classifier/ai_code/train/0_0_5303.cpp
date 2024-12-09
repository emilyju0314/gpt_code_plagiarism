#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long p, q;
        cin >> p >> q;

        long long x = 0;
        for (long long j = 1; j * j <= q; j++) {
            if (q % j == 0) {
                if (p % j != 0) {
                    x = max(x, j);
                }
                if (p % (q / j) != 0) {
                    x = max(x, q / j);
                }
            }
        }

        cout << p / x << endl;
    }

    return 0;
}