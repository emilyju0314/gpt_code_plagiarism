#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;

        long long result = 0;
        // Calculate the sum of elements from position l to r
        if (l % 2 == 1) {
            result = (r - l + 1) / 2;
            if ((r - l) % 2 == 0) {
                result *= -1;
            }
        } else {
            if ((r - l + 1) % 2 == 0) {
                result = (r - l + 1) / 2;
            } else {
                result = (r - l + 2) / 2;
                result *= -1;
            }
        }

        cout << result << endl;
    }

    return 0;
}