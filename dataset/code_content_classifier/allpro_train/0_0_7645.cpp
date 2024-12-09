#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        int steps = 100 / __gcd(k, 100 - k);

        cout << steps << endl;
    }

    return 0;
}