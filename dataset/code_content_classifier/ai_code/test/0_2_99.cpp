#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x0, n;
        cin >> x0 >> n;

        long long k = sqrt(2 * n + x0 * x0 - x0 + 0.25) - 0.5;
        long long sum = k * (k + 1) / 2;

        if (sum + x0 == n) {
            cout << x0 << endl;
        } else {
            long long diff = (sum + x0 - n) % 2;
            if (x0 % 2 == 0) {
                cout << x0 - diff << endl;
            } else {
                cout << x0 + diff << endl;
            }
        }
    }

    return 0;
}