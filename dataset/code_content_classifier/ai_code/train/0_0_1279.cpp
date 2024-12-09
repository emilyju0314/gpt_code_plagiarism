#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int rounds = 1;
    while (n > 1) {
        if (a <= n / 2 && b > n / 2) {
            break;
        }

        if (a > n / 2) {
            a -= n / 2;
        }
        if (b > n / 2) {
            b -= n / 2;
        }

        n /= 2;
        rounds++;
    }

    if (n == 1) {
        cout << "Final!";
    } else {
        cout << rounds;
    }

    return 0;
}