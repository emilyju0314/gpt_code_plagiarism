#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << 3 << endl;
    } else {
        cout << 3 + 2 * (n - 1) + (k - 2) << endl;
    }

    return 0;
}