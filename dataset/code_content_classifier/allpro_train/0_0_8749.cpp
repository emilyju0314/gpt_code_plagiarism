#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int x = k + 1; x <= 2 * n + 1; x++) {
        if ((x / k) * (x % k) == n) {
            cout << x << endl;
            break;
        }
    }

    return 0;
}