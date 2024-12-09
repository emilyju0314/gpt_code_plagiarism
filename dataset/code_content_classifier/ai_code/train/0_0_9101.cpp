#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long n;
        cin >> n;

        int moves = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else if (n % 3 == 0) {
                n = 2 * n / 3;
            }
            else if (n % 5 == 0) {
                n = 4 * n / 5;
            }
            else {
                break;
            }
            moves++;
        }

        if (n == 1) {
            cout << moves << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}